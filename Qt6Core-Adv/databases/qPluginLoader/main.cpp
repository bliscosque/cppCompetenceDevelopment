#include <QCoreApplication>
#include <QDebug>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QPluginLoader>
#include <QVariant>

void connectDB()
{
    qInfo() << "Opening Database";
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("db4free.net");
    db.setDatabaseName("qt6cadb"); //Change this to your config
    db.setUserName("qt6cadb"); //Change this to your config
    db.setPassword("qt6cadb-password"); //Change this to your config

    if(!db.open())
    {
        qInfo() << "Failed to connect!";
        qInfo() << db.lastError().text();
        return;
    }

    //Do stuff once connected!

    qInfo() << "Connected!";

    db.close();
}

bool testPlugin()
{
    qInfo() << "Testing plugin";
    //QPluginLoader loader("<PATH TO QT>/gcc_64/plugins/sqldrivers/libqsqlmysql.so"); //Change this!
    QPluginLoader loader("C:\\Qt\\6.5.1\\mingw_64\\plugins\\sqldrivers\\qsqlmysql.dll"); //Change this!

    qInfo() << loader.metaData();

    if(loader.load())
    {
        qInfo() << "Loaded the plugin";
        return true;
    }

    qInfo() << loader.errorString();
    return false;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    if(testPlugin())
    {
        connectDB();
    }

    return a.exec();
}
