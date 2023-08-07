#include "absolutelayout.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    absoluteLayout w;
    w.show();
    return a.exec();
}
