#include "recenttabsplanview.h"
#include <QDebug>


RecentTabsPlanView::RecentTabsPlanView(QObject *parent) :
    QAbstractListModel(parent)
{

}

RecentTabsPlanView::~RecentTabsPlanView()
{

}

int RecentTabsPlanView::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid())
        return 0;

    return m_recentIngredientList.count();

}

QVariant RecentTabsPlanView::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= m_recentIngredientList.count())
    {
        return QVariant();
    }

    switch (role) {
    case IngredientName:
        return m_recentIngredientList[index.row()]->m_ingredientName;
    case IngredientProcess:
        return m_recentIngredientList[index.row()]->m_ingredientProcess;
    case TotalWeight:
        return m_recentIngredientList[index.row()]->m_totalWeight;
    case IsCurrentItem:
        return m_recentIngredientList[index.row()]->m_ingredientName == m_currentItem;
    default:
        return QVariant();

    }
}

QHash<int, QByteArray> RecentTabsPlanView::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles.insert(IngredientName, "itemOrderId");
    roles.insert(IngredientProcess, "orderNumber");
    roles.insert(TotalWeight, "orderId");
    roles.insert(IsCurrentItem, "currentItem");

    return roles;
}

void RecentTabsPlanView::addRecentItem(QString ingredientName, QString ingredientProcess, float totalWeight)
{
    int isItemPresent = searchRecentItem(ingredientName);
    if( isItemPresent == -1) {
        beginResetModel();
        RecentIngredientPtr recent (new RecentIngredient);
        recent->m_ingredientName = ingredientName;
        recent->m_ingredientProcess = ingredientProcess;
        recent->m_totalWeight = totalWeight;
        m_recentIngredientList.append(recent);
        endResetModel();
    } else {
        m_recentIngredientList[isItemPresent]->m_ingredientProcess = ingredientProcess;
    }
    setCurrentItem(ingredientName);

}

void RecentTabsPlanView::removeRecentItem(int recentIndex)
{
    beginResetModel();
    m_recentIngredientList.removeAt(recentIndex);
    endResetModel();

}

void RecentTabsPlanView::setCurrentItem(QString itemId)
{
    beginResetModel();
    m_currentItem = itemId;
    endResetModel();
}

int RecentTabsPlanView::searchRecentItem(QString orderId) const
{
    for(int counter = 0; counter < m_recentIngredientList.count(); ++counter){
        if(orderId == m_recentIngredientList[counter]->m_ingredientName)
            return counter;
    }
    return -1;
}
