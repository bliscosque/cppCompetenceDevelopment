#include "widget.h"

Widget::Widget(QObject *parent)
    : QObject{parent}
{
    m_isSender = false;
}

void Widget::workStarted()
{
    qInfo() << this <<  "Started" << sender();
}

void Widget::workFinished()
{
    qInfo() << this <<  "Finished" << sender();
    m_isActive = false;
}

void Widget::workReady(int i)
{
    qInfo() << this << "Work" << i << sender();
}

void Widget::run()
{
    if(m_isSender) //estou produzindo...
    {
        qInfo() << this << "Starting work...";
        emit started(); //emite o sinal de started

        for(int i = 0; i < 10; i++)
        {
            qInfo() << this << "Update...";
            emit update(i); //emite o sinal de update
            QThread::currentThread()->msleep(500);
        }
        qInfo() << this << "Finished...";
        emit finished(); //emite o sinal de finished
    }
    else // estou consumindo...
    {
        qInfo() << this << "Waiting for signals...";
        m_isActive = true;
        while(m_isActive) //o falso é setado no workFinished
        {
            QThread::currentThread()->msleep(100);
        }
    }

    qInfo() << this << "Done";
}

bool Widget::isSender() const
{
    return m_isSender;
}

void Widget::setIsSender(bool newIsSender)
{
    m_isSender = newIsSender;
}
