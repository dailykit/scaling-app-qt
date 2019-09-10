#ifndef INGREDIENTDETAILVIEWMODEL_H
#define INGREDIENTDETAILVIEWMODEL_H

#include <QSqlTableModel >
#include <QDebug>
#include <QMetaType>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlQuery>
#include "DailyKitCore/External/WebServices/retrievewebappdata.h"

#include <QQmlEngine>
#include <QJSEngine>

class IngredientDetailViewModel : public QSqlTableModel
{
    Q_OBJECT

public:
    explicit IngredientDetailViewModel(QObject *parent = nullptr);
    virtual ~IngredientDetailViewModel() override;

    void setQuery(const QString &query);
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

public slots:

   void onWebDataChanged();

private:

    int m_recordCount;
    static const QString IngredientDetailViewQuery;
    RetrieveWebAppData *dataPage;
    static const QString TAG;
};

#endif // INGREDIENTDETAILVIEWMODEL_H
