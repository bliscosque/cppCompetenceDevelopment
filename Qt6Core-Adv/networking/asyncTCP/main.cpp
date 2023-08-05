#include <QCoreApplication>
#include <QThread>
#include "client.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QThread::currentThread()->setObjectName("Main Thread");

    Client client;
    client.connectToHost("www.voidrealms.com",80);

    qInfo() << "*** Free to do other things ***";
    return a.exec();
}
