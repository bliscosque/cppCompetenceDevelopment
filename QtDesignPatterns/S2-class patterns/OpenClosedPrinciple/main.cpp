#include <QCoreApplication>
#include <QDebug>
#include <QStringList>
#include "shop.h"
#include "cofeemachine.h"
#include "caffeeinator3000.h"

/*
 What
 Open/Closed Principle

 Define
 Software entities (classes, modules, functions, etc.) should be open for extension, but closed for modification

 Why
 Avoids breaking things in the future if we modify the code

 Example
 Many frameworks use inheritance but this creates tight coupling
 Example Qt uses inheritance mostly QTCPSocket and QSSLSocket
 We will use an interface so this example also complies with the other solid princibles

*/

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Shop shop;
    QStringList list;
    list << "Sugar" << "Flavoring";

    //CofeeMachine machine;
    //como usa IF, podemos substituir o CofeeMachine por outra que implementa iBrew
    Caffeeinator3000 caf3000;

    shop.sellDrink(list,&caf3000);

    return a.exec();
}
