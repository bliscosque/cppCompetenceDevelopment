#ifndef MUSIC_H
#define MUSIC_H

#include <QObject>
#include <QString>
#include <QDate>

class Music
{
public:
    Music();

    QString album() const;
    void setAlbum(const QString &newAlbum);

    QString artist() const;
    void setArtist(const QString &newArtist);

    QString notes() const;
    void setNotes(const QString &newNotes);

    QDate relase() const;
    void setRelase(const QDate &newRelase);

private:
    QString m_album;
    QString m_artist;
    QString m_notes;
    QDate m_relase;

};

#endif // MUSIC_H
