#ifndef ORDERVIEWMODEL_H
#define ORDERVIEWMODEL_H


#include <QDebug>
#include <QMetaType>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QAbstractListModel>
#include <QQmlEngine>
#include <QJSEngine>

#include "../Models/itemdetails.h"


class OrderViewModel : public QAbstractListModel
{
    Q_OBJECT

    Q_PROPERTY(int orderCount READ orderCount NOTIFY orderCountChanged)

    enum MyRoles {
        ItemOrderId = Qt::UserRole + 1,
        OrderId,
        ItemName,
        ItemServing,
        IngredientCount,
        PackedIngredientCount,
        OrderNumber
    };

public:

    explicit OrderViewModel(QObject *parent = nullptr);
    virtual ~OrderViewModel() override;

    int orderCount() const;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

public slots:

    void onOrderDetailsReceived(QList<ItemDetailsPtr>);

signals:
    void orderCountChanged();

private:

    int m_recordCount;
    static const QString OrderViewQuery;
    QList<ItemDetailsPtr> m_itemDetails;
};

//Q_DECLARE_METATYPE(OrderViewModel)

#endif // ORDERVIEWMODEL_H
