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


void Dialog::on_btnExecWParent_clicked()
{
    Dialog2 *dialog=new Dialog2(this);
    dialog->exec();
}


void Dialog::on_btnExecWoParent_clicked()
{
    //Pointer does not delete itself!!!
    Dialog2 *dialog = new Dialog2(nullptr);
    dialog->exec();
}

