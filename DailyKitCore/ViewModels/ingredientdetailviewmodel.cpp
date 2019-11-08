#include "ingredientdetailviewmodel.h"

//const QString IngredientDetailViewModel::IngredientDetailViewQuery = "select * from ingredient_detail";
//const QString IngredientDetailViewModel::TAG ="IngredientDetailViewModel.cpp : ";

IngredientDetailViewModel::IngredientDetailViewModel(QObject *parent)
    : QAbstractListModel(parent)
{

}

IngredientDetailViewModel::~IngredientDetailViewModel()
{
    //    qDebug() <<TAG<<"deleted";
}


QVariant IngredientDetailViewModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= m_ingredientsDetailsList.count())
    {
        return QVariant();

    }

    switch (role) {
    case IngredientDetailId:
        return m_ingredientsDetailsList[index.row()]->IngredientDetails::m_ingredientDetailId;
    case IngredientName:
        return m_ingredientsDetailsList[index.row()]->IngredientDetails::m_ingredientName;
    case IngredientProcess:
        return m_ingredientsDetailsList[index.row()]->IngredientDetails::m_ingredientProcess;
    case IngredientQuantity:
        return m_ingredientsDetailsList[index.row()]->IngredientDetails::m_ingredientQuantity;
    case IngredientWeight:
        return m_ingredientsDetailsList[index.row()]->IngredientDetails::m_ingredientMeasure;
    case IngredientIsPacked:
        return m_ingredientsDetailsList[index.row()]->IngredientDetails::m_isIngredientPacked;
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> IngredientDetailViewModel::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles.insert(IngredientDetailId, "ingredientDetailId");
    roles.insert(IngredientName, "ingredientName");
    roles.insert(IngredientProcess, "ingredientProcess");
    roles.insert(IngredientQuantity, "quantity");
    roles.insert(IngredientWeight, "ingredientWeight");
    roles.insert(IngredientIsPacked, "ingredientIsPacked");

    return roles;
}

int IngredientDetailViewModel::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid())
        return 0;

    return m_ingredientsDetailsList.count();

}

void IngredientDetailViewModel::setIngredientDetails(IngredientDetailsPtr details)
{
    m_ingredientsDetailsList.append(details);
}

QList<IngredientDetailsPtr> IngredientDetailViewModel::ingredientList()
{
    return m_ingredientsDetailsList;
}

