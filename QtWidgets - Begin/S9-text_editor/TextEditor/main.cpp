#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setOrganizationName("Thiago APP");
    a.setOrganizationDomain("http://donthavedomain.com");
    a.setApplicationName("Text Editor");
    a.setApplicationDisplayName("My Text Editor"); // titulo da janela
    a.setApplicationVersion("0.0.1a");

    MainWindow w;
    w.show();
    return a.exec();
}
