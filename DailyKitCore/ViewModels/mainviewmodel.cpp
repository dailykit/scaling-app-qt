#include "mainviewmodel.h"

MainViewModel::MainViewModel(QObject *parent) :
    QObject(parent),
    m_databaseProxy(DbProxy::dbInstance()),
    m_orderModel(new OrderViewModel()),
    m_ingredientsManipulation(new ManipulateIngredients()),
    m_recentPlanView(new RecentTabsPlanView)

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


ManipulateIngredients* MainViewModel::manipulateIngredients()
{
    if(m_ingredientsManipulation != nullptr) {
        return m_ingredientsManipulation;
    }
    else  {
        m_ingredientsManipulation = new ManipulateIngredients();
        return m_ingredientsManipulation;
    }
}

RecentTabsPlanView *MainViewModel::recentIngredients()
{
    if(m_recentPlanView != nullptr) {
        return m_recentPlanView;
    }
    else  {
        m_recentPlanView = new RecentTabsPlanView();
        return m_recentPlanView;
    }

}
