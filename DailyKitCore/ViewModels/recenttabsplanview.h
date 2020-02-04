/**********************************************************************
 * Class is responsible for handling data related to Recent Tabs which
 * are opened in planning mode
 * *******************************************************************/

#ifndef RECENTTABSPLANVIEW_H
#define RECENTTABSPLANVIEW_H

#include <QObject>
#include <QAbstractListModel>
#include <QSharedPointer>

struct RecentIngredient{
    QString m_ingredientName;
    QString m_ingredientProcess;
    float m_totalWeight;
    RecentIngredient()
    {
    }

    ~RecentIngredient() {}

};
Q_DECLARE_METATYPE(RecentIngredient)
typedef QSharedPointer<RecentIngredient> RecentIngredientPtr;

class RecentTabsPlanView : public QAbstractListModel
{
    Q_OBJECT
public:

    enum Roles{
        IngredientName,
        IngredientProcess,
        TotalWeight,
        IsCurrentItem
    };

    RecentTabsPlanView(QObject *parent = nullptr);
    virtual ~RecentTabsPlanView() override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE void addRecentItem(QString orderNumber, QString itemOrderId, float orderId);
    Q_INVOKABLE void removeRecentItem(int index);
    Q_INVOKABLE void setCurrentItem(QString itemId);


private:

    QList<RecentIngredientPtr> m_recentIngredientList;
    QString m_currentItem;

    int searchRecentItem(QString orderId) const;
};

#endif // RECENTTABSPLANVIEW_H
