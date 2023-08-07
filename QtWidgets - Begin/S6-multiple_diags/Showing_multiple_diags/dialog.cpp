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


void Dialog::on_btnWParent_clicked()
{
    Dialog2 *dialog=new Dialog2(this);
    dialog->show();
}


void Dialog::on_btnWoParent_clicked()
{
    Dialog2 *dialog=new Dialog2(nullptr);
    dialog->show();
}
