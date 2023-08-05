#include <QCoreApplication>
#include <QThread>
#include <QThreadPool>
#include <QMutex>
#include "counter.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread::currentThread()->setObjectName("Main");
    QThreadPool* pool = QThreadPool::globalInstance();

    //mutex e valor serao compartilhados com todas as instancias
    QMutex mutex;
    int value=0;

    for (int i=0;i<100;i++) {
        Counter* c=new Counter(&mutex,&value);
        c->setAutoDelete(true);
        pool->start(c);
    }

    return a.exec();
}
