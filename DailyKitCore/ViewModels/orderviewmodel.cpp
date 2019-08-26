#include "orderviewmodel.h"

OrderViewModel::OrderViewModel(QObject *parent) :
    QAbstractListModel (parent)
{

}

OrderViewModel::OrderViewModel(const OrderViewModel &obj)
{
    m_itemsList = obj.m_itemsList;
}

OrderViewModel::~OrderViewModel()
{

}

int OrderViewModel::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid())
        return 0;

    return m_itemsList.count();

}

QVariant OrderViewModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid() || m_itemsList.size() == 0)
        return QVariant();

    ItemDetailsPtr item = m_itemsList.at(index.row());
    if(item.isNull())
        return QVariant();

    switch(role) {
    case OrderId:
        return item->orderId();
    case RecipeName:
        return item->recipeName();
    case Servings:
        return item->recipeServings();
    }

    return QVariant();

}

QHash<int, QByteArray> OrderViewModel::roleNames() const
{
    QHash<int, QByteArray> roles;
       roles[OrderId] = "orderId";
       roles[RecipeName] = "recipeName";
       roles[Servings] = "servings";
       return roles;

}
