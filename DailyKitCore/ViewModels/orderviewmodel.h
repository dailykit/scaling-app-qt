#ifndef ORDERVIEWMODEL_H
#define ORDERVIEWMODEL_H


#include <QDebug>
#include <QMetaType>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QSqlQuery>
#include "../Models/itemdetails.h"
#include "DailyKitCore/External/WebServices/retrievewebappdata.h"

#include <QQmlEngine>
#include <QJSEngine>

class OrderViewModel : public QSqlQueryModel
{
    Q_OBJECT

public:

    explicit OrderViewModel(QObject *parent = nullptr);
    virtual ~OrderViewModel() override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;
    void setQuery(const QString &query);
public slots:
   void onWebDataChanged();

private:

    int m_recordCount;
    static const QString OrderViewQuery;
    RetrieveWebAppData *dataPage;
};

//Q_DECLARE_METATYPE(OrderViewModel)

#endif // ORDERVIEWMODEL_H
