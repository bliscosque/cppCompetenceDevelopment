#include "dialog.h"
#include "./ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    init();
    load();
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_comboBox_currentIndexChanged(int index)
{
    ui->lblSelected->setText(QString::number(index) + " = " + ui->comboBox->currentText());
}


void Dialog::on_btnSave_clicked()
{
    QSettings settings("MySoft", "MyApp");
    settings.setValue("settings",ui->comboBox->currentIndex());

    QMessageBox::information(this,"Saved","Selection saved, please close and re-open the app");
}

void Dialog::init()
{
    ui->comboBox->clear();
    for (int i=0;i<10;i++) {
        ui->comboBox->addItem("Item number: "+ QString::number(i));
    }
}

void Dialog::load()
{
    QSettings settings("MySoft", "MyApp");
    QVariant value=settings.value("settings",0);
    bool ok;
    int idx=value.toInt(&ok);
    if (!ok) {
        QMessageBox::critical(this,"Loading error","Error loading settings");
        return;
    }

    //QMessageBox::information(this,"Saved",QString::number(idx));

    if (idx < ui->comboBox->count()) {
        ui->comboBox->setCurrentIndex(idx);
    }
    else {
        ui->comboBox->setCurrentIndex(0);
    }
}

