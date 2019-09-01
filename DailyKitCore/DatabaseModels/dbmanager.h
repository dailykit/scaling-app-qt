#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QStandardPaths>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDir>
#include <QFile>
#include <QDebug>

class DBManager
{
public:
    DBManager();
    ~DBManager();

    static void connectToDatabase();
    static void createOrderTable();
    static void createItemTable();

   static const QString DRIVER;
   static const QString ORDERTABLE;
   static const QString ITEMSTABLE;
};

#endif // DBMANAGER_H
