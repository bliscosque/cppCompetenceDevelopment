#include "absolutelayout.h"
#include "ui_absolutelayout.h"

absoluteLayout::absoluteLayout(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::absoluteLayout)
{
    ui->setupUi(this);
}

absoluteLayout::~absoluteLayout()
{
    delete ui;
}

