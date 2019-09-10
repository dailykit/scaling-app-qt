#ifndef ITEMVIEWMODEL_H
#define ITEMVIEWMODEL_H

#include <QSqlTableModel >
#include <QDebug>
#include <QMetaType>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlQuery>
#include "../Models/itemdetails.h"
#include "DailyKitCore/External/WebServices/retrievewebappdata.h"

#include <QQmlEngine>
#include <QJSEngine>

class ItemViewModel : public QSqlTableModel
{
    Q_OBJECT

public:

    explicit ItemViewModel(QObject *parent = nullptr);
    virtual ~ItemViewModel() override;

    void setQuery(const QString &query);
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;


public slots:

   void onWebDataChanged();

private:

    int m_recordCount;
    static const QString ItemViewQuery;
    RetrieveWebAppData *dataPage;
    static const QString TAG;
};

#endif // ITEMVIEWMODEL_H
