#include "caffeeinator3000.h"

Caffeeinator3000::Caffeeinator3000(QObject *parent)
    : QObject{parent}
{

}

void Caffeeinator3000::addIngredients(QStringList &list)
{
    foreach(QString itm,list)
        qInfo() << "Adding: " << itm;
}

void Caffeeinator3000::brew()
{
    qInfo() << "Heating";
    marketing();
    qInfo() << "Preparing";
    qInfo() << "Beep";
}

void Caffeeinator3000::marketing()
{
    qInfo() << "Fire!!";
    qInfo() << "LOUD MUSIC!!!";
}
