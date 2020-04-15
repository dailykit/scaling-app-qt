#include "recenttabsmodel.h"
#include <QDebug>


RecentTabsModel::RecentTabsModel(QObject *parent) :
    QAbstractListModel(parent)
{

}

RecentTabsModel::~RecentTabsModel()
{

}

int RecentTabsModel::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid())
        return 0;

    return m_recentOrderList.count();

}

QVariant RecentTabsModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= m_recentOrderList.count())
    {
        return QVariant();
    }

    switch (role) {
    case OrderId:
        return m_recentOrderList[index.row()]->m_orderId;
    case OrderNumber:
        return m_recentOrderList[index.row()]->m_orderNumber;
    case ItemOrderId:
        return m_recentOrderList[index.row()]->m_itemOrderId;
    case IsCurrentItem:
        return m_recentOrderList[index.row()]->m_itemOrderId == m_currentItem;
    default:
        return QVariant();

    }
}

QHash<int, QByteArray> RecentTabsModel::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles.insert(ItemOrderId, "itemOrderId");
    roles.insert(OrderNumber, "orderNumber");
    roles.insert(OrderId, "orderId");
    roles.insert(IsCurrentItem, "currentItem");

    return roles;
}

void RecentTabsModel::addRecentItem(QString orderNumber, QString itemOrderId, QString orderId)
{
    int isItemPresent = searchRecentItem(orderNumber);
    if( isItemPresent == -1) {
        beginResetModel();
        RecentOrderPtr recent (new RecentOrder);
        recent->m_orderNumber = orderNumber;
        recent->m_itemOrderId = itemOrderId;
        recent->m_orderId = orderId;
        m_recentOrderList.append(recent);
        endResetModel();
    } else {
        m_recentOrderList[isItemPresent]->m_itemOrderId = itemOrderId;
    }
    setCurrentItem(itemOrderId);

}

void RecentTabsModel::removeRecentItem(int recentIndex)
{
    beginResetModel();
    m_recentOrderList.removeAt(recentIndex);
    endResetModel();
}

void RecentTabsModel::setCurrentItem(QString itemId)
{
    beginResetModel();
    m_currentItem = itemId;
    endResetModel();
}

int RecentTabsModel::searchRecentItem(QString orderId) const
{
    for(int counter = 0; counter < m_recentOrderList.count(); ++counter){
        if(orderId == m_recentOrderList[counter]->m_orderNumber)
            return counter;
    }
    return -1;
}
