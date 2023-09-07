#ifndef CAFFEEINATOR3000_H
#define CAFFEEINATOR3000_H

#include <QObject>
#include <QDebug>
#include <QStringList>
#include "interfaces/iBrew.h"

class Caffeeinator3000 : public QObject, public iBrew
{
    Q_OBJECT
public:
    explicit Caffeeinator3000(QObject *parent = nullptr);

signals:


    // iBrew interface
public:
    void addIngredients(QStringList &list) override;
    void brew() override;
    // new function
    void marketing();
};

#endif // CAFFEEINATOR3000_H
