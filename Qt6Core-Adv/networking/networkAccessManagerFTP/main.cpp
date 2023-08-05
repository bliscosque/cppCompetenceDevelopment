#include <QCoreApplication>
#include <QDateTime>
#include <QDebug>
#include "worker.h"
#include <QNetworkAccessManager>

void upload(Worker* worker, QString path)
{
    QString location = "ftp://speedtest.tele2.net/upload/VoidRealms-" + QString::number(QDateTime::currentSecsSinceEpoch()) + ".bin";
    worker->upload(location,path);

}

void download(Worker* worker, QString path)
{
    QString location = "ftp://speedtest.tele2.net/512KB.zip";
    worker->download(location,path);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QNetworkAccessManager manager;
    qInfo() << manager.supportedSchemes(); //Shows what is supported in Qt 6

    Worker worker;
    //upload(&worker,"test.txt");
    //download(&worker,"test.zip");

    return a.exec();
}
