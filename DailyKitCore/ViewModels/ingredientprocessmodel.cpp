#include "ingredientprocessmodel.h"
#include <QDebug>

IngredientProcessModel::IngredientProcessModel(QObject *parent) :
    QAbstractListModel(parent)
{

}


QVariant IngredientProcessModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= m_ingredientProcessList.count())
    {
        return QVariant();

    }

    switch (role) {
    case IngredientQuantity:
        return m_ingredientProcessList[index.row()]->m_ingredientProcessWeight;
    case IngredientProcessName:
        return m_ingredientProcessList[index.row()]->m_ingredientProcess;
    case IngredientPackedCount:
        return m_ingredientProcessList[index.row()]->m_ingredientPackedCount;
    case IngredientProcessCount:
        return m_ingredientProcessList[index.row()]->m_ingredientProcessCount;
    case CurrentItem:
        return m_ingredientProcessList[index.row()]->m_ingredientProcess == m_currentItem;
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> IngredientProcessModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles.insert(IngredientId, "ingredientDetailId");
    roles.insert(IngredientQuantity, "ingredientWeight");
    roles.insert(IngredientProcessName, "ingredientProcess");
    roles.insert(IngredientPackedCount, "ingredientPackedCount");
    roles.insert(IngredientProcessCount, "ingredientProcessCount");
    roles.insert(CurrentItem, "currentItem");

    return roles;
}

int IngredientProcessModel::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid())
        return 0;

    return m_ingredientProcessList.count();
}

void IngredientProcessModel::setIngredientProcess(IngredientProcessPtr details)
{
    m_ingredientProcessList.append(details);
}

QList<IngredientProcessPtr> IngredientProcessModel::ingredientProcessList()
{
    return m_ingredientProcessList;
}

void IngredientProcessModel::setCurrentItem(QString ingredientProcess)
{
   qDebug() << "current item" << ingredientProcess;
    beginResetModel();
    m_currentItem = ingredientProcess;
    emit currentItemChanged();
    endResetModel();

}

QString IngredientProcessModel::currentItem() const
{
    return m_currentItem;
}
