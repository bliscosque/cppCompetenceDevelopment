#include "counter.h"

Counter::Counter(QMutex *mutex, int *value)
{
    m_value=value;
    m_mutex=mutex;
}

void Counter::run()
{
    //m_mutex->lock();
    QMutexLocker locker(m_mutex); //faz o lock e o unlock automaticamente

    QThread::currentThread()->msleep(50);
    *m_value=*m_value+1;
    qInfo() << *m_value << QThread::currentThread();

    //m_mutex->unlock(); //faz o unlock
}
