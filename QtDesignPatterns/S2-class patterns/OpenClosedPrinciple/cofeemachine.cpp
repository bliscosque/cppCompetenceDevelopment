#include "cofeemachine.h"

CofeeMachine::CofeeMachine(QObject *parent)
    : QObject{parent}
{

}

void CofeeMachine::addIngredients(QStringList &list)
{
    foreach(QString itm,list)
        qInfo() << "Adding: " << itm;
}

void CofeeMachine::brew()
{
    qInfo() << "Heating";
    qInfo() << "Preparing";
    qInfo() << "Beep";
}
