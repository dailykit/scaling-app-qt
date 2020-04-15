#ifndef RECENTAPPSMODEL_H
#define RECENTAPPSMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include <QString>
#include <QSharedPointer>

struct RecentAppsDetails {
    QString url;
    QString appName;
    QString index;
    QString color;
    RecentAppsDetails()
    {}

    ~RecentAppsDetails() {}

};
Q_DECLARE_METATYPE(RecentAppsDetails)
typedef QSharedPointer<RecentAppsDetails> RecentAppsDetailsPtr;

class RecentAppsModel : public QAbstractListModel
{
    Q_OBJECT

    enum Roles{
        URL,
        AppName,
        IsCurrentItem,
        AppColor
    };

public:
    RecentAppsModel(QObject *parent = nullptr);

    virtual ~RecentAppsModel() override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE void addRecentItem(QString url, QString appName, int index, QString color);
    Q_INVOKABLE void removeRecentItem(int index);
    Q_INVOKABLE void setCurrentItem(int index);

private:
    int searchRecentItem(int index) const;

    int m_currentIndex;
    QList<RecentAppsDetailsPtr> m_recentAppDetails;
};

#endif // RECENTAPPSMODEL_H
