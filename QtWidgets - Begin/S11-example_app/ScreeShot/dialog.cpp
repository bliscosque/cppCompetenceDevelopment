#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    foreach(QScreen *screen, QGuiApplication::screens())
        ui->cbScreens->addItem(screen->name());
    ui->lblScreen->setText("");
    ui->btnSave->setEnabled(false);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_btnScreenShot_clicked()
{
    QScreen *screen=QGuiApplication::screens().at(ui->cbScreens->currentIndex());
    if(!screen) {
        QMessageBox::critical(this,"Error","Could not get the screen");
        return;
    }
    hide();
    QTimer::singleShot(500,this,&Dialog::shoot);
}


void Dialog::on_btnSave_clicked()
{
    QString path=QFileDialog::getSaveFileName(this,"Save",QString(),"PNG Image (*.png)");
    if(path.isEmpty()) return;

    QFileInfo fi(path);
    if(fi.exists()) {
        QMessageBox::StandardButton btn = QMessageBox::question(this,"Exist","File already exists would you like to overwrite it?");
        if(btn != QMessageBox::StandardButton::Yes) return;
    }
    if(!m_image.save(path,"PNG"))
        QMessageBox::critical(this,"Error","could not save image!");
}

void Dialog::shoot()
{
    QScreen *screen=QGuiApplication::screens().at(ui->cbScreens->currentIndex());
    m_image=screen->grabWindow(0);
    QPixmap m_scaled=m_image.scaled(ui->lblScreen->width(),ui->lblScreen->height(),Qt::AspectRatioMode::KeepAspectRatio);
    ui->lblScreen->setPixmap(m_scaled);
    ui->btnSave->setEnabled(true);
    show();
}

