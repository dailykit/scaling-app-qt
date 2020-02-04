#ifndef RECENTTABSMODEL_H
/***************************************************************************
 * Class is responsible for handling the recent tabs that were opened by the user
 * in the real time
 ***************************************************************************/

#define RECENTTABSMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include <QSharedPointer>

struct RecentOrder{
    QString m_itemOrderId;
    QString m_orderNumber;
    QString m_orderId;
    RecentOrder()
    {
    }

    ~RecentOrder() {}

};
Q_DECLARE_METATYPE(RecentOrder)
typedef QSharedPointer<RecentOrder> RecentOrderPtr;

class RecentTabsModel : public QAbstractListModel
{
    Q_OBJECT
public:

    enum Roles{
        OrderNumber,
        ItemOrderId,
        OrderId,
        IsCurrentItem
    };

    RecentTabsModel(QObject *parent = nullptr);
    virtual ~RecentTabsModel() override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE void addRecentItem(QString orderNumber, QString itemOrderId, QString orderId);
    Q_INVOKABLE void removeRecentItem(int index);
    Q_INVOKABLE void setCurrentItem(QString itemId);


private:

    QList<RecentOrderPtr> m_recentOrderList;
     QString m_currentItem;
   int searchRecentItem(QString orderId) const;
};

#endif // RECENTTABSMODEL_H
