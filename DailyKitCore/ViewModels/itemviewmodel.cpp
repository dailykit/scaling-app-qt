#include "itemviewmodel.h"

const QString ItemViewModel::ItemViewQuery = "select * from itemDetails";
const QString ItemViewModel::TAG ="ItemViewModel.cpp : ";

ItemViewModel::ItemViewModel(QObject *parent)
    : QSqlTableModel(parent),m_recordCount(0),dataPage(new RetrieveWebAppData)
{
    if(dataPage) {
        dataPage->getOrderList();
        connect(dataPage, &RetrieveWebAppData::webDataChanged, this, &ItemViewModel::onWebDataChanged);
    }
    setQuery(ItemViewQuery);
}

ItemViewModel::~ItemViewModel()
{
    qDebug() <<TAG<<"deleted";
}

void ItemViewModel::setQuery(const QString &query)
{
    QSqlQueryModel::setQuery(query);

    if (this->query().record().isEmpty()) {
        qWarning() <<TAG<< "SQLiteModel::setQuery() -" << this->query().lastError();

    }

    m_recordCount = record().count();
    qDebug() <<TAG<< "Records: " << m_recordCount;
}

QVariant ItemViewModel::data(const QModelIndex &index, int role) const
{
    QVariant value = QSqlQueryModel::data(index, role);
    if(role < Qt::UserRole)
    {
        value = QSqlQueryModel::data(index, role).toString();
    }
    else
    {
        int columnIdx = role - Qt::UserRole - 1;
        QModelIndex modelIndex = this->index(index.row(), columnIdx);
        value = QSqlQueryModel::data(modelIndex, Qt::DisplayRole).toString();
    }
    return value;
}

QHash<int, QByteArray> ItemViewModel::roleNames() const
{
    QHash<int, QByteArray> roles;// = QAbstractTableModel::roleNames();
    for( int i = 0; i < record().count(); i++) {
        qDebug() << "roles" << record().fieldName(i).toLatin1();
        roles[Qt::UserRole + i + 1] = record().fieldName(i).toLatin1();
    }
    return roles;
}

int ItemViewModel::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid())
        return 0;

    return m_recordCount;

}

void ItemViewModel::onWebDataChanged()
{
    setQuery(ItemViewQuery);
}
