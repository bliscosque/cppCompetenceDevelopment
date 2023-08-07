#include "editor.h"
#include "ui_editor.h"

Editor::Editor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Editor)
{
    ui->setupUi(this);
}

Editor::~Editor()
{
    delete ui;
}

Music Editor::music() const
{
    return m_music;
}

void Editor::setMusic(const Music &newMusic)
{
    m_music = newMusic;

    ui->txtArtist->setText(m_music.artist());
    ui->txtAlbum->setText(m_music.album());
    ui->ptxtNotes->setPlainText(m_music.notes());
    ui->edtRelease->setDate(m_music.relase());
}

void Editor::on_buttonBox_accepted()
{
    m_music.setAlbum(ui->txtAlbum->text());
    m_music.setArtist(ui->txtArtist->text());
    m_music.setNotes(ui->ptxtNotes->toPlainText());
    m_music.setRelase(ui->edtRelease->date());

    accept();
}


void Editor::on_buttonBox_rejected()
{
    reject();
}

