#include "ingredientviewmodel.h"

const QString IngredientViewModel::IngredientViewQuery ="select * from ingredient where ingredientItemId = :itemId";
const QString IngredientViewModel::TAG ="IngredientViewModel.cpp : ";

IngredientViewModel::IngredientViewModel(QObject *parent)
    : QAbstractListModel(parent),
    dataPage(new RetrieveWebAppData)
{
    if(dataPage) {
        dataPage->getOrderList();
        connect(dataPage, &RetrieveWebAppData::webDataChanged, this, &IngredientViewModel::onWebDataChanged);
    }
    setQuery("");
}

IngredientViewModel::~IngredientViewModel()
{
    qDebug() <<TAG<<"deleted";
}

void IngredientViewModel::setQuery(const QString &itemId)
{
    QSqlQuery query;
    query.prepare("select * from ingredients where ingredientItemId = :itemId");
    query.bindValue(":itemId", itemId);

    if (query.exec()) {

        qDebug() << "query exece" << query.size();
        while (query.next()){
           qDebug() << query.value(0).toString();
        }

    }
    else{
        qDebug() <<"Errors occured with sql statement";
        qDebug() <<query.lastError();
    }

}

QVariant IngredientViewModel::data(const QModelIndex &index, int role) const
{
//    QVariant value = QSqlQueryModel::data(index, role);
//    if(role < Qt::UserRole)
//    {
//        value = QSqlQueryModel::data(index, role).toString();
//    }
//    else
//    {
//        int columnIdx = role - Qt::UserRole - 1;
//        QModelIndex modelIndex = this->index(index.row(), columnIdx);
//        value = QSqlQueryModel::data(modelIndex, Qt::DisplayRole).toString();
//    }
    return QVariant();
}

QHash<int, QByteArray> IngredientViewModel::roleNames() const
{
//    QHash<int, QByteArray> roles;// = QAbstractTableModel::roleNames();
//    for( int i = 0; i < record().count(); i++) {
//        qDebug() << "roles" << record().fieldName(i).toLatin1();
//        roles[Qt::UserRole + i + 1] = record().fieldName(i).toLatin1();
//    }
//    return roles;
}

int IngredientViewModel::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid())
        return 0;

    return m_recordCount;

}

void IngredientViewModel::onWebDataChanged()
{
    //setQuery(IngredientViewQuery);
}
