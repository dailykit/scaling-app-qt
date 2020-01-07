#ifndef DBPROXY_H
#define DBPROXY_H

#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>
#include <QObject>
#include "../Models/itemdetails.h"
#include "DailyKitCore/External/WebServices/retrievewebappdata.h"

class DbProxy : public QObject
{
    Q_OBJECT

signals:
    void ingredientPackedChanged(const QString &ingredientDetailId);

public:

    void setIngredientAsPacked(const QString &ingredientId);
    void openDatabase();
    void getOrders();

    static DbProxy *dbInstance();

public slots:
   void currentOrdersReceived();

signals:
    void orderDetailsChanged(QList<ItemDetailsPtr> details);

private:
    static const QString UPDATEINGREDIENTPACKED ;
    static const QString ORDERVIEWQUERY;
    DbProxy(QObject *parent = nullptr);

    QString m_ingredientDetailUpdated;
    static DbProxy *m_databaseProxy;
    RetrieveWebAppData *m_dataPage;

};

#endif // DBPROXY_H
