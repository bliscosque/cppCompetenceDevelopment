#include <QCoreApplication>
#include <QDebug>
#include <QTcpSocket>
#include "mysocket.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MySocket socket;

    qInfo() << "Connection...";
    socket.connectToHost("www.google.com",80);
    socket.waitForConnected();

    qInfo() << "Connected";

    qInfo() << "Closing...";
    socket.close();
    if (socket.isOpen()) socket.waitForDisconnected();

    qInfo() << "Complete!";

    return a.exec();
}
