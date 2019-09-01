#ifndef ORDERVIEWMODEL_H
#define ORDERVIEWMODEL_H

#include <QAbstractListModel>
#include <QList>
#include <QMetaType>
#include "../Models/itemdetails.h"
#include <QSqlTableModel>
class OrderViewModel : public QAbstractListModel
{
public:
    enum {
        OrderId = Qt::UserRole + 1,
        RecipeName,
        Servings
    };

   explicit OrderViewModel( QObject *parent = nullptr);
    OrderViewModel(const OrderViewModel& obj);
    virtual ~OrderViewModel() override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

private:
    QList<ItemDetailsPtr> m_itemsList;
};

Q_DECLARE_METATYPE(OrderViewModel)

#endif // ORDERVIEWMODEL_H
