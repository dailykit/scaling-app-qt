#include "planviewitemmodel.h"



PlanViewItemModel::PlanViewItemModel(QObject *parent) :
    QAbstractListModel(parent),
    m_totalWeight(0.0)
{

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

}

QHash<int, QByteArray> PlanViewItemModel::roleNames() const
{

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

    QSqlQuery query;
    query.prepare("SELECT ingredientId, ingredientQuantity FROM ingredientDetails WHERE ingredientName = ? AND ingredientProcess=? ");
    query.addBindValue(ingredientName);
    query.addBindValue(ingredientProcess);
    if(query.exec())
    {
        while (query.next()) {
            qDebug() << "ingredient id" << query.value(0).toString() << "--" << query.value(1).toFloat();
            QSqlQuery ingredientQuery, itemsQuery;
            ingredientQuery.prepare("SELECT ingredientItemId FROM ingredients WHERE ingredientId = ? ");
            ingredientQuery.addBindValue(query.value(0).toString());
            ingredientQuery.exec();

            PlanItemDetailsPtr ptr(new PlanItemDetails());
            ptr->setItemId(ingredientQuery.value(0).toString());

            while(ingredientQuery.next())
            {
                qDebug() << "item id" << ingredientQuery.value(0).toString();
                itemsQuery.prepare("SELECT orderId, itemName  FROM itemDetails  WHERE itemOrderId =  ? ");
                itemsQuery.addBindValue(ingredientQuery.value(0).toString());
                itemsQuery.exec();

                while(itemsQuery.next()){
                    qDebug() << "items" << itemsQuery.value(0).toString() << " " <<
                                itemsQuery.value(1).toString() << " " <<
                                query.value(1).toFloat();
                    ptr->setOrderId(itemsQuery.value(0).toString());
                    ptr->setItemName(itemsQuery.value(1).toString());
                    ptr->setIngredientWeight(query.value(1).toFloat());
                }
            }
        }

    } else {
        qDebug() << "query failed";
    }

}
