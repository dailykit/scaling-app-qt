#ifndef ITEMVIEWMODEL_H
#define ITEMVIEWMODEL_H

#include <QDebug>
#include <QMetaType>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlQuery>
#include "../Models/itemdetails.h"
#include <QAbstractListModel>


class ItemViewModel : public QAbstractListModel
{
    Q_OBJECT

public:

    enum MyRoles {
        ItemOrderId = Qt::UserRole + 1,
        OrderId,
        ItemName,
        IngredientCount,
        PackedIngredientCount,
        OrderNumber,
        IsCurrentItem
    };

    explicit ItemViewModel(QObject *parent = nullptr);
    virtual ~ItemViewModel() override;


    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;


public slots:
void setQuery(int orderId);

void setCurrentItem(QString itemOrderId);

private:

    QList<ItemDetailsPtr> m_itemDetails;
    QString m_currentItem;
    static const QString ItemViewQuery;
    static const QString TAG;
};

#endif // ITEMVIEWMODEL_H
