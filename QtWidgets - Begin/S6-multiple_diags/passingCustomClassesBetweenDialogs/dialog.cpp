#include "dialog.h"
#include "./ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    QPushButton *btn=new QPushButton("Edit",this);
    ui->buttonBox->addButton(btn,QDialogButtonBox::ButtonRole::ActionRole);
    connect(btn,&QPushButton::clicked,this,&Dialog::on_edit);

    m_music.setArtist("Artist...");
    m_music.setAlbum("Album...");
    m_music.setRelase(QDate(2023,7,20));
    m_music.setNotes("No notes...");

    load();
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_buttonBox_accepted()
{
    QMessageBox::information(this,"Selection",ui->plainTextEdit->toPlainText());
    accept();
}


void Dialog::on_buttonBox_rejected()
{
    reject();
}

void Dialog::on_edit()
{
    Editor *edt=new Editor(this);
    edt->setMusic(m_music);

    edt->exec();

    m_music=edt->music();

    load();

    delete edt;
}

void Dialog::load()
{
    ui->plainTextEdit->clear();
    ui->plainTextEdit->setReadOnly(true);

    QString data;
    data.append("Artist: " + m_music.artist() + "\r\n");
    data.append("Album: " + m_music.album() + "\r\n");
    data.append("Release: " + m_music.relase().toString() + "\r\n");
    data.append("Notes: " + m_music.notes() + "\r\n");

    ui->plainTextEdit->setPlainText(data);
}

