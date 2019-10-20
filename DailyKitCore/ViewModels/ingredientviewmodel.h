#ifndef INGREDIENTVIEWMODEL_H
#define INGREDIENTVIEWMODEL_H


#include <QDebug>
#include <QMetaType>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QAbstractListModel>
#include <QMultiMap>
#include "../Models/ingredients.h"
#include "DailyKitCore/External/WebServices/retrievewebappdata.h"
#include "ingredientdetailviewmodel.h"

#include <QQmlEngine>

#include <QJSEngine>

class IngredientViewModel : public QAbstractListModel
{
    Q_OBJECT

    enum MyRoles{
        IngredientId,
        IngredientSlipName,
        IngredientDetailList,
        IngredientProcess,
        IngredientQuantity,
        IngredientWeight,
        IngredientPacked,
        IngredientDetailId
    };

public:
    explicit IngredientViewModel(QObject *parent = nullptr);
    virtual ~IngredientViewModel() override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    Q_INVOKABLE void getIngredients(const QString ItemId);

public slots:

   void setQuery(const QString &itemId);

private slots:
   void updateIngredientDetail(const QString &indgredientDetailsId);

private:

    RetrieveWebAppData *dataPage;

    QList<IngredientsPtr> m_ingredientsList;

    QList<QSharedPointer<IngredientDetailViewModel> > m_detailsModel;

    static const QString IngredientViewQuery;
    static const QString TAG;
};

#endif // INGREDIENTVIEWMODEL_H
