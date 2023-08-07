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

void Dialog::init()
{
    QStringList headers;
    headers << "My Items";
    model.setHorizontalHeaderLabels(headers);

    QStandardItem *root=model.invisibleRootItem();
    for (int p=0;p<10;p++) {
        QStandardItem* parentItem=new QStandardItem(QString("Parent %0").arg(p));
        root->appendRow(parentItem);

        for (int c=0;c<10;c++) {
            QStandardItem* child=new QStandardItem(QString("Child %0").arg(c));
            parentItem->appendRow(child);

            for (int s=0;s<10;s++) {
                QStandardItem* subchild=new QStandardItem(QString("SubChild %0").arg(s));
                child->appendRow(subchild);
            }
        }
    }

    ui->treeView->setModel(&model);
}

