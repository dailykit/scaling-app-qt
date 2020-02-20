#include "mainviewmodel.h"

MainViewModel::MainViewModel(QObject *parent) :
    QObject(parent),
    m_databaseProxy(DbProxy::dbInstance()),
    m_orderModel(new OrderViewModel),
    m_ingredientsManipulation(new ManipulateIngredients),
    m_recentPlanView(new RecentTabsPlanView),
    m_ingredientsModel(new IngredientViewModel),
    m_recentTabs(new RecentTabsModel),
    m_itemsModel(new ItemViewModel),
    m_settingsModel(new SettingsModel),
    m_planViewModel(new PlanViewModel),
    m_planViewItemModel(new PlanViewItemModel)
{
    connect(m_databaseProxy, &DbProxy::orderDetailsChanged, m_orderModel, &OrderViewModel::onOrderDetailsReceived);

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

OrderViewModel *MainViewModel::ordersViewModel()
{
    return m_orderModel;

}

IngredientViewModel *MainViewModel::ingredientsModel()
{
    return m_ingredientsModel;

}

RecentTabsModel *MainViewModel::recentTabs()
{
    return m_recentTabs;
}

ItemViewModel *MainViewModel::itemsModel()
{
    return m_itemsModel;
}

SettingsModel *MainViewModel::settingsModel()
{
    return m_settingsModel;
}

PlanViewModel *MainViewModel::planViewModel()
{
    return m_planViewModel;
}

PlanViewItemModel *MainViewModel::planViewItemModel()
{
    return m_planViewItemModel;
}

WeighingScaleModel *MainViewModel::weighingScale()
{
    return  WeighingScaleModel::weighScaleInstance();
}
