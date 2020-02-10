#include "planviewitemmodel.h"
#include "../DatabaseModels/dbproxy.h"


PlanViewItemModel::PlanViewItemModel(QObject *parent) :
    QAbstractListModel(parent),
    m_totalWeight(0.0)
{
    connect(DbProxy::dbInstance(), &DbProxy::ingredientDeleted, this, &PlanViewItemModel::onIngredientDeleted);
}


PlanViewItemModel::~PlanViewItemModel()
{

}


float PlanViewItemModel::totalWeight() const
{
    return m_totalWeight;
}

void PlanViewItemModel::setTotalWeight(float weight)
{
    m_totalWeight = weight;
    emit totalWeightChanged();
}

QString PlanViewItemModel::ingredientName() const
{
    return m_ingredientName;
}

void PlanViewItemModel::setIngredientName(QString ingredient)
{
    m_ingredientName = ingredient;
    emit ingredientNameChanged();
}

QVariant PlanViewItemModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= m_planItemDetailsList.count())
    {
        return QVariant();
    }

    switch (role) {
    case ItemsId:
        return m_planItemDetailsList[index.row()]->itemId();
    case OrderId:
        return m_planItemDetailsList[index.row()]->orderId();
    case ItemName:
        return m_planItemDetailsList[index.row()]->itemName();
    case IngredientWeight:
        return m_planItemDetailsList[index.row()]->ingredientWeight();
    case IngredientDetailId:
        return m_planItemDetailsList[index.row()]->ingredientDetailId();
    case IngredientId:
        return m_planItemDetailsList[index.row()]->ingredientId();
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> PlanViewItemModel::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles.insert(OrderId, "orderId");
    roles.insert(IngredientId, "ingredientId");
    roles.insert(ItemName, "itemName");
    roles.insert(IngredientWeight, "ingredientWeight");
    roles.insert(ItemsId, "itemId");
    roles.insert(IngredientDetailId, "ingredientDetailId");

    return roles;
}

int PlanViewItemModel::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid())
        return 0;

    return m_planItemDetailsList.count();
}

void PlanViewItemModel::getItems(QString ingredientProcess, QString ingredientName, float totalWeight)
{
    setTotalWeight(totalWeight);
    setIngredientName(ingredientName);
    qDebug() << "get Items" << ingredientProcess;

    m_planItemDetailsList.clear();
    QSqlQuery query;
    query.prepare("SELECT ingredientId, ingredientQuantity, ingredientDetailId FROM ingredientDetails WHERE ingredientName = ? AND ingredientProcess=? ");
    query.addBindValue(ingredientName);
    query.addBindValue(ingredientProcess);
    if(query.exec())
    {
        beginResetModel();
        while (query.next()) {

            PlanItemDetailsPtr ptr(new PlanItemDetails());
            QSqlQuery ingredientQuery, itemsQuery;


            ingredientQuery.prepare("SELECT ingredientItemId FROM ingredients WHERE ingredientId = ? ");
            ingredientQuery.addBindValue(query.value(0).toString());
            ingredientQuery.exec();
            ptr->setIngredientId(query.value(0).toString());

            while(ingredientQuery.next())
            {
                ptr->setItemId(ingredientQuery.value(0).toString());
                ptr->setIngredientDetailId(query.value(2).toString());

                itemsQuery.prepare("SELECT orderId, itemName  FROM itemDetails  WHERE itemOrderId =  ? ");
                itemsQuery.addBindValue(ingredientQuery.value(0).toString());
                itemsQuery.exec();

                while(itemsQuery.next())
                {
                    ptr->setOrderId(itemsQuery.value(0).toString());
                    ptr->setItemName(itemsQuery.value(1).toString());
                    ptr->setIngredientWeight(query.value(1).toFloat());
                }
            }
            m_planItemDetailsList.append(ptr);
            endResetModel();
        }

    } else {
        qDebug() << "query failed";
    }

}

void PlanViewItemModel::onIngredientDeleted(const QString ingredientId)
{
    qDebug() << "ingredient delete received" << ingredientId;
    for(int index = 0; index < m_planItemDetailsList.count(); ++index)
    {
        if(m_planItemDetailsList.at(index)->ingredientId() == ingredientId)
        {
            qDebug() << "ingredient delete received" << "found";
            QModelIndex modelIndex = createIndex(index, 0);
            beginRemoveRows(modelIndex.parent(), modelIndex.row(), modelIndex.row());
            m_planItemDetailsList.removeAt(index);
            endRemoveRows();

        }
    }

}
