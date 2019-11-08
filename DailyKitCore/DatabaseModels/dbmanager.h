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
    static void createIngredientTable();
    static void createIngredientDetailTable();

    void openDatabase();

    static const QString DRIVER;
    static const QString ORDERTABLE;
    static const QString ITEMSTABLE;
    static const QString INGREDIENT_TABLE;
    static const QString INGREDIENT_DETAIL_TABLE;
};

#endif // DBMANAGER_H
