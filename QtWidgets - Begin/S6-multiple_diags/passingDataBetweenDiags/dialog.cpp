#include "dialog.h"
#include "./ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_btnSelect_clicked()
{
    Selections *dlg=new Selections(this);
    //set the def
    dlg->setSelected(ui->lineEdit->text());

    dlg->exec();

    //read back the new selection
    ui->lineEdit->setText(dlg->selected());
}


void Dialog::on_buttonBox_accepted()
{
    accept();
}


void Dialog::on_buttonBox_rejected()
{
    reject();
}

