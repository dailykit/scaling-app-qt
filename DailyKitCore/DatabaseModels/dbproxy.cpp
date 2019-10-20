#include "dbproxy.h"

const QString DbProxy::UPDATEINGREDIENTPACKED = "UPDATE ingredientDetails SET isPacked = ? where ingredientDetailId = ?";
DbProxy* DbProxy::m_databaseProxy = nullptr;

DbProxy::DbProxy(QObject *parent) :
    QObject(parent)
{
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

DbProxy *DbProxy::dbInstance()
{
    if(m_databaseProxy == nullptr) {
        m_databaseProxy = new DbProxy();
    }
    return m_databaseProxy;

}
