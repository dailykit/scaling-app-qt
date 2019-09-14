#include "ingredientviewmodel.h"

const QString IngredientViewModel::IngredientViewQuery ="SELECT ingredientDetails.ingredientDetailId, ingredientDetails.ingredientName, "
                                                        "ingredientDetails.ingredientQuantity, ingredientDetails.ingredientMsr, ingredientDetails.ingredientProcess, ingredientDetails.isPacked, ingredients.ingredientId, ingredients.slipName FROM ingredientDetails "
                                                        "INNER JOIN ingredients ON ingredientDetails.ingredientId = ingredients.ingredientId WHERE ingredients.ingredientItemId = ?";

const QString IngredientViewModel::TAG ="IngredientViewModel.cpp : ";

IngredientViewModel::IngredientViewModel(QObject *parent)
    : QAbstractListModel(parent),
      dataPage(new RetrieveWebAppData)
{
}

IngredientViewModel::~IngredientViewModel()
{
    qDebug() <<TAG<<"deleted";
}

void IngredientViewModel::setQuery(const QString &itemId)
{
    qDebug() << "setQuery called "<< itemId;
    QSqlQuery query;


    query.prepare(IngredientViewQuery);
    query.addBindValue(itemId);

    if (query.exec()) {

       m_ingredientsList.clear();
        qDebug() << "query exece" << query.size();
        while (query.next()){
            IngredientsPtr ptr(new Ingredients());
            ptr->ingredientDetails()->IngredientDetails::m_ingredientDetailId  = query.value(0).toString();
            ptr->ingredientDetails()->IngredientDetails::m_ingredientName = query.value(1).toString();
            ptr->ingredientDetails()->IngredientDetails::m_ingredientQuantity = query.value(2).toString();
            ptr->ingredientDetails()->IngredientDetails::m_ingredientMeasure = query.value(3).toString();
            ptr->ingredientDetails()->IngredientDetails::m_ingredientProcess =  query.value(4).toString();
            ptr->ingredientDetails()->IngredientDetails::m_isIngredientPacked = query.value(5).toInt();
            ptr->setIngredientId(query.value(6).toString());
            ptr->setIngredientName(query.value(7).toString());

            m_ingredientsList.append(ptr);
        }

    }
    else{
        qDebug() <<"Errors occured with sql statement" <<  query.executedQuery();
        qDebug() <<query.lastError();
    }

}

QVariant IngredientViewModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= m_ingredientsList.count())
    {
        return QVariant();

    }

    switch (role) {
    case IngredientId:
        return m_ingredientsList[index.row()]->ingredientId();
    case IngredientSlipName:
        return m_ingredientsList[index.row()]->ingredientName();
    case IngredientDetailId:
        return m_ingredientsList[index.row()]->ingredientDetails()->IngredientDetails::m_ingredientDetailId;
    case IngredientName:
        return m_ingredientsList[index.row()]->ingredientDetails()->IngredientDetails::m_ingredientName;
    case IngredientProcess:
        return m_ingredientsList[index.row()]->ingredientDetails()->IngredientDetails::m_ingredientProcess;
    case IngredientQuantity:
        return m_ingredientsList[index.row()]->ingredientDetails()->IngredientDetails::m_ingredientQuantity;
    case IngredientWeight:
        return m_ingredientsList[index.row()]->ingredientDetails()->IngredientDetails::m_ingredientMeasure;
    case IngredientIsPacked:
        return m_ingredientsList[index.row()]->ingredientDetails()->IngredientDetails::m_isIngredientPacked;
    default:
        return QVariant();

    }
}

QHash<int, QByteArray> IngredientViewModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles.insert(IngredientId, "ingredientId");
    roles.insert(IngredientSlipName, "ingredientSlipName");
    roles.insert(IngredientDetailId, "ingredientDetailId");
    roles.insert(IngredientName, "ingredientName");
    roles.insert(IngredientProcess, "ingredientProcess");
    roles.insert(IngredientQuantity, "quantity");
    roles.insert(IngredientWeight, "ingredientWeight");
    roles.insert(IngredientIsPacked, "ingredientIsPacked");
    return roles;
}

int IngredientViewModel::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid())
        return 0;

    return m_ingredientsList.count();
}

void IngredientViewModel::getIngredients(const QString ItemId)
{
    qDebug()<< "ingredient data fetching" << ItemId;
    setQuery(ItemId);
}
