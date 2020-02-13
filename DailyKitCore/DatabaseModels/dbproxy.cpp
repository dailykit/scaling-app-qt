#include "dbproxy.h"

const QString DbProxy::UPDATEINGREDIENTPACKED = "UPDATE ingredientDetails SET isWeighed = ? where ingredientDetailId = ?";
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

void DbProxy::setIngredientAsWeighed(const QString& ingredientDetailId)
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
        emit ingredientWeighedChanged(m_ingredientDetailUpdated);
    }

}

void DbProxy::getOrders()
{
    m_dataPage->getOrderList();
}

void DbProxy::deleteIngredient(const QString ingredientId)
{
    QSqlQuery deleteIngredientDetailsQuery;

    deleteIngredientDetailsQuery.prepare("DELETE FROM ingredientDetails WHERE ingredientId = ?");
    deleteIngredientDetailsQuery.addBindValue(ingredientId);
    if (deleteIngredientDetailsQuery.exec()) {
        QSqlQuery deleteIngredientsQuery;
        deleteIngredientsQuery.prepare("DELETE FROM ingredients WHERE ingredientId = ?");
        deleteIngredientsQuery.addBindValue(ingredientId);
        if(deleteIngredientsQuery.exec()) {
            qDebug() << "Ingredient deleted";
            emit ingredientDeleted(ingredientId);
        }
        else {
            qDebug() << deleteIngredientsQuery.lastError() << ingredientId;
        }
    } else {
        qDebug() <<deleteIngredientDetailsQuery.lastError() << ingredientId;
    }
}

void DbProxy::setIngredientAsPackedCompleted(const QString ingredientDetailId)
{
    QSqlQuery getIngredientId;
    qDebug() << "ingredient as packed completed" << ingredientDetailId;

    getIngredientId.prepare("SELECT ingredientId FROM ingredientDetails WHERE ingredientDetailId = ?");
    getIngredientId.addBindValue(ingredientDetailId);

    if(getIngredientId.exec()) {
        QSqlQuery checkIsWeighed;
        if(getIngredientId.first()) {
            qDebug() << "getIngredientId.value(0).toString()" << getIngredientId.value(0).toString();
            checkIsWeighed.prepare("SELECT isWeighed FROM ingredientDetails WHERE ingredientId = ?");
            checkIsWeighed.addBindValue(getIngredientId.value(0).toString());
        }
        int counter = 0;
        int nextCount = 0;
        if(checkIsWeighed.exec()) {
            while(checkIsWeighed.next()) {
                nextCount++;
                if(checkIsWeighed.value(0).toInt() == 1) {
                    counter++;
                }
            }
            if(counter == nextCount) {
                QSqlQuery ingredientAsPacked;
                ingredientAsPacked.prepare("UPDATE ingredients set isPackedComplete = ? WHERE ingredientId = ?");
                const int value = 1;
                ingredientAsPacked.addBindValue(value);
                ingredientAsPacked.addBindValue(getIngredientId.value(0).toString());
                if(ingredientAsPacked.exec()) {
                    QSqlQuery itemId;
                    itemId.prepare("SELECT ingredientItemId FROM ingredients WHERE ingredientId = ?");
                    itemId.addBindValue(getIngredientId.value(0).toString());
                    qDebug() << Q_FUNC_INFO << "ingredient packed complete" << itemId.first();
                    if(itemId.exec()) {
                        if(itemId.first())
                        {
                            emit ingredientPackingCompleted(itemId.value(0).toString());
                        } else {
                             qDebug() << Q_FUNC_INFO << itemId.lastError();
                        }
                    }
                } else {
                    qDebug() << Q_FUNC_INFO <<"ingredient as packed query"<< ingredientAsPacked.lastError();
                }
            }
        } else {
            qDebug() << "check is weighed query" << checkIsWeighed.lastError();
        }

    } else {
        qDebug() << "ingredient Id" << getIngredientId.lastError();
    }

}

void DbProxy::currentOrdersReceived()
{
    QSqlQuery query;

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
