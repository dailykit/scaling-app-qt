#include "mainviewmodel.h"

MainViewModel::MainViewModel(QObject *parent) :
    QObject(parent),
    m_databaseProxy(DbProxy::dbInstance()),
    m_orderModel(new OrderViewModel())

{
    connect(m_databaseProxy, &DbProxy::orderDetailsChanged, m_orderModel, &OrderViewModel::onOrderDetailsReceived);

}

OrderViewModel *MainViewModel::getOrdersModel()
{
    return m_orderModel;
}

void MainViewModel::getOrders()
{
    m_databaseProxy->currentOrdersReceived();
}
