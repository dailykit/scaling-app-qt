#ifndef RECENTTABSMODEL_H
#define RECENTTABSMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include <QSharedPointer>

struct RecentOrder{
    QString m_itemOrderId;
    QString m_orderNumber;
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
        OrderId,
        ItemOrderId
    };

    RecentTabsModel(QObject *parent = nullptr);
    virtual ~RecentTabsModel() override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE void addRecentItem(QString orderNumber, QString itemOrderId);
    Q_INVOKABLE void removeRecentItem(int index);


private:

    QList<RecentOrderPtr> m_recentOrderList;

   int searchRecentItem(QString orderId) const;
};

#endif // RECENTTABSMODEL_H
