#include "mysocket.h"

MySocket::MySocket(QObject *parent)
    : QTcpSocket{parent}
{

}

void MySocket::close()
{
    qInfo() << "Do smth b4 closing...";
    //QTcpSocket::close(); //Break things if we don't know exactly parent implementation
}
