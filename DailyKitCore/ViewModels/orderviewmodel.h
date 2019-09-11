#ifndef ORDERVIEWMODEL_H
#define ORDERVIEWMODEL_H


#include <QDebug>
#include <QMetaType>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QSqlQuery>
#include  <QAbstractListModel>
#include <QQmlEngine>
#include <QJSEngine>

#include "../Models/itemdetails.h"
#include "DailyKitCore/External/WebServices/retrievewebappdata.h"

class OrderViewModel : public QAbstractListModel
{
    Q_OBJECT

    enum MyRoles {
        ItemOrderId = Qt::UserRole + 1,
        OrderId,
        ItemName,
        ItemServing,
        UserIcon,
        RightArrow
    };

public:

    explicit OrderViewModel(QObject *parent = nullptr);
    virtual ~OrderViewModel() override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

public slots:
    /**
    * @brief onWebDataChanged - when the web data changes, this slot is called to update the list
    */
    void setQuery();
    void onWebDataChanged();

private:

    int m_recordCount;
    static const QString OrderViewQuery;
    RetrieveWebAppData *dataPage;
    QList<ItemDetailsPtr> m_itemDetails;
};

//Q_DECLARE_METATYPE(OrderViewModel)

#endif // ORDERVIEWMODEL_H
