#ifndef COFEEMACHINE_H
#define COFEEMACHINE_H

#include <QObject>
#include <QDebug>
#include <QStringList>
#include "interfaces/iBrew.h"

class CofeeMachine : public QObject, public iBrew
{
    Q_OBJECT
public:
    explicit CofeeMachine(QObject *parent = nullptr);


signals:


    // iBrew interface
public:
    void addIngredients(QStringList &list) override;
    void brew() override;
};

#endif // COFEEMACHINE_H
