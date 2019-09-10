#include "orderviewmodel.h"


const QString OrderViewModel::OrderViewQuery = "select * from itemDetails";

OrderViewModel::OrderViewModel(QObject *parent) :
    QSqlQueryModel(parent),
    m_recordCount(0),
    dataPage(new RetrieveWebAppData)
{

    if(dataPage) {
        dataPage->getOrderList();
        connect(dataPage, &RetrieveWebAppData::webDataChanged, this, &OrderViewModel::onWebDataChanged);
    }
    setQuery(OrderViewQuery);
}


OrderViewModel::~OrderViewModel()
{
    qDebug() << "deleted";
}

int OrderViewModel::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid())
        return 0;

    return m_recordCount;

}

void OrderViewModel::setQuery(const QString &queryString)
{
    QSqlQueryModel::setQuery(queryString);

    if (this->query().record().isEmpty()) {
        qWarning() << "SQLiteModel::setQuery() -" << this->query().lastError();

    }

    m_recordCount = record().count();
    qDebug() << "Records: " << m_recordCount;


}

void OrderViewModel::onWebDataChanged()
{
    qDebug() << "Web data changed";
    setQuery(OrderViewQuery);

}

QHash<int, QByteArray> OrderViewModel::roleNames() const
{
    QHash<int, QByteArray> roles;// = QAbstractTableModel::roleNames();
    for( int i = 0; i < record().count(); i++) {
        qDebug() << "roles" << record().fieldName(i).toLatin1();
        roles[Qt::UserRole + i + 1] = record().fieldName(i).toLatin1();
    }
    return roles;
}

QVariant OrderViewModel::data(const QModelIndex &index, int role) const
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
