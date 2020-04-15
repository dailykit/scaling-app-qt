#include "recentappsmodel.h"
#include <QDebug>

RecentAppsModel::RecentAppsModel(QObject *parent) :
    QAbstractListModel(parent),
    m_currentIndex(0)
{
}

RecentAppsModel::~RecentAppsModel()
{

}

int RecentAppsModel::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid())
        return 0;

    return m_recentAppDetails.count();
}

QVariant RecentAppsModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= m_recentAppDetails.count())
    {
        return QVariant();
    }

    switch (role) {
    case URL:
        return m_recentAppDetails[index.row()]->url;
    case AppName:
        return m_recentAppDetails[index.row()]->appName;
    case IsCurrentItem:
        return m_recentAppDetails[index.row()]->index == m_currentIndex;
    case AppColor:
        return m_recentAppDetails[index.row()]->color;
    default:
        return QVariant();

    }
}

QHash<int, QByteArray> RecentAppsModel::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles.insert(URL, "url");
    roles.insert(AppName, "appName");
    roles.insert(IsCurrentItem, "currentItem");
    roles.insert(AppColor, "appColor");

    return roles;

}

void RecentAppsModel::addRecentItem(QString url, QString appName, int index, QString color)
{
    qDebug() << "colorrr" << color;
    int isItemPresent = searchRecentItem(index);
    if( isItemPresent == -1) {
        beginResetModel();
        RecentAppsDetailsPtr recent (new RecentAppsDetails);
        recent->url = url;
        recent->appName = appName;
        recent->index = index;
        recent->color = color;
        m_recentAppDetails.append(recent);
        endResetModel();
    }
    setCurrentItem(index);
}

void RecentAppsModel::removeRecentItem(int index)
{
    beginResetModel();
    m_recentAppDetails.removeAt(index);
    endResetModel();
}

void RecentAppsModel::setCurrentItem(int index)
{
    beginResetModel();
    m_currentIndex = index;
    endResetModel();
}


int RecentAppsModel::searchRecentItem(int index) const
{
    for(int counter = 0; counter < m_recentAppDetails.count(); ++counter){
        if(index == m_recentAppDetails[counter]->index)
            return counter;
    }
    return -1;
}


