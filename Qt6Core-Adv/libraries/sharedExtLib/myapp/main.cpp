#include <QCoreApplication>
#include "inc/mylib_global.h"
#include "inc/mylib.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Mylib lib;
    lib.test();

    return a.exec();
}
