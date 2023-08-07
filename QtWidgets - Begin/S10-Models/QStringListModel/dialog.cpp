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
    accept();
}


void Dialog::on_buttonBox_rejected()
{
    reject();
}

void Dialog::add()
{
    QString value=QInputDialog::getText(this,"Add Item", "Enter the item to add");
    if(value.isEmpty()) return;

    //Use inherited functions of QAbstractModel
    if (model.insertRow(model.rowCount())) { //insere uma nova linha
        QModelIndex idx=model.index((model.rowCount()-1),0);
        model.setData(idx,value); //insere o dado no modelo
    }
    qInfo() << list; // a lista (dados) não são atualizados
}

void Dialog::remove()
{
    QModelIndex idx=ui->listView->currentIndex();
    model.removeRow(idx.row());
}

void Dialog::init()
{
    //setup the data
    list.append("Cat");
    list.append("Dog");
    list.append("Hamster");

    //setup the model, using data
    model.setStringList(list);

    //setup the view
    ui->listView->setModel(&model);

    //Build UI
    QPushButton *btnAdd=new QPushButton("Add", this);
    QPushButton *btnRemove=new QPushButton("Remove",this);

    connect(btnAdd,&QPushButton::clicked,this,&Dialog::add);
    connect(btnRemove,&QPushButton::clicked,this,&Dialog::remove);

    ui->buttonBox->addButton(btnAdd,QDialogButtonBox::ButtonRole::ActionRole);
    ui->buttonBox->addButton(btnRemove,QDialogButtonBox::ButtonRole::ActionRole);
}

