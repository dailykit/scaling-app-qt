#include "dbproxy.h"

const QString DbProxy::UPDATEINGREDIENTPACKED = "UPDATE ingredientDetails SET isPacked = ? where ingredientDetailId = ?";
const QString DbProxy::ORDERVIEWQUERY = "SELECT  itemDetails.itemOrderId, itemDetails.orderId, itemDetails.itemName, itemDetails.itemServing"
                                        ", (SELECT Count(I1.ingredientId) FROM ingredients I1 WHERE I1.ingredientItemId = itemDetails.itemOrderId) as counttotal"
                                        ", (SELECT SUM(I2.isPackedComplete) FROM ingredients I2 WHERE I2.ingredientItemId = itemDetails.itemOrderId) as turnover "
                                        ", (SELECT orderNumber FROM orderDetails where orderDetails.orderId = itemDetails.orderId) FROM itemDetails";
DbProxy* DbProxy::m_databaseProxy = nullptr;

DbProxy::DbProxy(QObject *parent) :
    QObject(parent),
    m_dataPage(new RetrieveWebAppData)
{
    //currentOrdersReceived();
    if(m_dataPage != nullptr) {
        if(m_dataPage) {
            m_dataPage->getOrderList();
            connect(m_dataPage, &RetrieveWebAppData::webDataChanged, this, &DbProxy::currentOrdersReceived);
        }
    }

}

void DbProxy::setIngredientAsPacked(const QString& ingredientDetailId)
{
    qDebug() << "ingredient packed" << ingredientDetailId;
    m_ingredientDetailUpdated = ingredientDetailId;
    QSqlQuery query;
    const int value = 1;
    query.prepare(UPDATEINGREDIENTPACKED);
    query.addBindValue(value);
    query.addBindValue(ingredientDetailId);

    if(!query.exec()){
        qDebug() <<query.lastError();
    } else {
        qDebug() << "success update";
        emit ingredientPackedChanged(m_ingredientDetailUpdated);
    }

}

void DbProxy::getOrders()
{
    m_dataPage->getOrderList();
}

void DbProxy::currentOrdersReceived()
{ QSqlQuery query;

    if(query.exec(ORDERVIEWQUERY)) {
        QList<ItemDetailsPtr> itemDetails;
        qDebug() << "current received";
        if(query.next()) {

            while (query.next()){
                ItemDetailsPtr ptr(new ItemDetails());
                ptr->setItemOrderId(query.value(0).toString());
                ptr->setOrderId(query.value(1).toString());
                ptr->setRecipeName(query.value(2).toString());
                ptr->setRecipeServings(query.value(3).toString());
                ptr->setIngredientCount(query.value(4).toInt());
                ptr->setPackedIngredients(query.value(5).toInt());
                ptr->setOrderNumber(query.value(6).toInt());

                itemDetails.append(ptr);
            }
        }
        emit orderDetailsChanged(itemDetails);
    }
    else {
        qDebug() <<"Errors accured with sql statement";
        qDebug() <<query.lastError();
    }
}

DbProxy *DbProxy::dbInstance()
{
    if(m_databaseProxy == nullptr) {
        m_databaseProxy = new DbProxy();
    }
    return m_databaseProxy;

}
