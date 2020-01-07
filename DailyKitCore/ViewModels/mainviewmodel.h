#ifndef MAINVIEWMODEL_H
#define MAINVIEWMODEL_H

#include <QObject>
#include "orderviewmodel.h"
#include "DailyKitCore/DatabaseModels/dbproxy.h"

class MainViewModel : public QObject
{
    Q_OBJECT
public:
    explicit MainViewModel(QObject *parent = nullptr);

signals:

public slots:
    OrderViewModel *getOrdersModel();

    Q_INVOKABLE void getOrders();

private:
    DbProxy *m_databaseProxy;
    OrderViewModel *m_orderModel;
};

#endif // MAINVIEWMODEL_H
