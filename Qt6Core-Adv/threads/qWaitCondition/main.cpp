#include <QCoreApplication>
#include <QWaitCondition>
#include <QMutex>
#include <QThread>
#include "producer.h"
#include "consumer.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QWaitCondition valueReady;
    QMutex mutex;
    QThread producerThread;
    QThread consumerThread;
    int value = 0;

    producer *producer1 = new producer(&mutex,&valueReady,&value);
    consumer *consumer1 = new consumer(&mutex,&valueReady,&value);

    producer1->moveToThread(&producerThread);
    consumer1->moveToThread(&consumerThread);

    QObject::connect(&producerThread,&QThread::started,producer1,&producer::run);
    QObject::connect(&consumerThread,&QThread::started,consumer1,&consumer::run);

    producerThread.start();
    consumerThread.start();

    return a.exec();
}
