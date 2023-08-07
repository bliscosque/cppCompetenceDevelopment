#include "finddialog.h"
#include "ui_finddialog.h"

FindDialog::FindDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindDialog)
{
    ui->setupUi(this);
    init();
    save();
}

FindDialog::~FindDialog()
{
    delete ui;
}

void FindDialog::on_buttonBox_accepted()
{
    save();
    accept();
}


void FindDialog::on_buttonBox_rejected()
{
    reject();
}

void FindDialog::goBack()
{
    save();
    m_backward=true;
    accept();
}

void FindDialog::init()
{
    QPushButton *btnBack=new QPushButton("Back",this);
    connect(btnBack,&QPushButton::clicked,this,&FindDialog::goBack);
    ui->buttonBox->addButton(btnBack,QDialogButtonBox::ActionRole);
}

void FindDialog::save()
{
    m_text=ui->txtEdit->text();
    m_caseSensitive=ui->chkCaseSensitive->isChecked();
    m_wholeWord=ui->chkMathWhole->isChecked();
    m_backward=false;
}

bool FindDialog::backward() const
{
    return m_backward;
}

bool FindDialog::wholeWord() const
{
    return m_wholeWord;
}

bool FindDialog::caseSensitive() const
{
    return m_caseSensitive;
}

QString FindDialog::text() const
{
    return m_text;
}

