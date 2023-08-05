#include "counter.h"

Counter::Counter(QMutex *mutex, int *value)
{
    m_value=value;
    m_mutex=mutex;
}

void Counter::run()
{
    //faz um lock até poder liberar o recurso
    m_mutex->lock();
    QThread::currentThread()->msleep(500);
    *m_value=*m_value+1;
    qInfo() << *m_value << QThread::currentThread();

    m_mutex->unlock(); //libera o lock
}
