#include "dialog.h"
#include "./ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    init();
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_buttonBox_accepted()
{
    QMessageBox::information(this,"Hello",ui->txtFirst->text());
    accept();
}


void Dialog::on_buttonBox_rejected()
{
    reject();
}

void Dialog::next()
{
    int idx=ui->stackedWidget->currentIndex();
    idx++;
    if (idx>ui->stackedWidget->count()) idx=ui->stackedWidget->count()-1;
    ui->stackedWidget->setCurrentIndex(idx);
    checkButtons();
}

void Dialog::back()
{
    int idx=ui->stackedWidget->currentIndex();
    idx--;
    if (idx<0) idx=0;
    ui->stackedWidget->setCurrentIndex(idx);
    checkButtons();
}

void Dialog::init()
{
    btnNext=new QPushButton("Next",this);
    btnBack=new QPushButton("Back",this);
    connect(btnNext,&QPushButton::clicked,this,&Dialog::next);
    connect(btnBack,&QPushButton::clicked,this,&Dialog::back);

    ui->buttonBox->addButton(btnBack,QDialogButtonBox::ButtonRole::ActionRole);
    ui->buttonBox->addButton(btnNext,QDialogButtonBox::ButtonRole::ActionRole);

    QWidget *widget=new QWidget(this);
    QLabel *lblNothing=new QLabel("Nothing...",this);
    QHBoxLayout *layout=new QHBoxLayout(this);
    layout->addWidget(lblNothing);
    widget->setLayout(layout);
    ui->stackedWidget->addWidget(widget);
    ui->stackedWidget->setCurrentIndex(0);

    checkButtons();

}

void Dialog::checkButtons()
{
    //1st page
    if (ui->stackedWidget->currentIndex()==0) {
        btnBack->setEnabled(false);
        btnNext->setEnabled(true);
        return;
    }
    //last page
    if (ui->stackedWidget->currentIndex()>=ui->stackedWidget->count()-1) {
        btnBack->setEnabled(true);
        btnNext->setEnabled(false);
        return;
    }
    btnBack->setEnabled(true);
    btnNext->setEnabled(true);
}

