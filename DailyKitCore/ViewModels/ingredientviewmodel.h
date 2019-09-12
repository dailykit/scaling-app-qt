#ifndef INGREDIENTVIEWMODEL_H
#define INGREDIENTVIEWMODEL_H


#include <QDebug>
#include <QMetaType>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QAbstractListModel>
#include "../Models/ingredients.h"
#include "DailyKitCore/External/WebServices/retrievewebappdata.h"

#include <QQmlEngine>
#include <QJSEngine>

class IngredientViewModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit IngredientViewModel(QObject *parent = nullptr);
    virtual ~IngredientViewModel() override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

public slots:

   void onWebDataChanged();
   void setQuery(const QString &itemId);

private:

    int m_recordCount;
    static const QString IngredientViewQuery;
    RetrieveWebAppData *dataPage;
    static const QString TAG;
};

#endif // INGREDIENTVIEWMODEL_H
