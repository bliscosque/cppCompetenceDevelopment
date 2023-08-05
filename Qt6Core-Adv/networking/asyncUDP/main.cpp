#include <QCoreApplication>
#include <QThread>
#include "worker.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread::currentThread()->setObjectName("Main Thread");
    Worker worker;
    worker.start();

    return a.exec();
}
