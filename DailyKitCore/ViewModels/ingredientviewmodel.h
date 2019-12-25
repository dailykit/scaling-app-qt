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
        IngredientDetailId,
        BackIcon
    };

    Q_PROPERTY(int orderNumber READ orderNumber WRITE setOrderNumber NOTIFY orderNumberChanged)
    Q_PROPERTY(QString itemName READ itemName WRITE setItemName NOTIFY itemNameChanged)

public:
    explicit IngredientViewModel(QObject *parent = nullptr);
    virtual ~IngredientViewModel() override;

    int orderNumber() const;
    void setOrderNumber(int order);

    QString itemName() const;
    void setItemName(QString item);


    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    Q_INVOKABLE void getIngredients(const QString ItemId);

public slots:

   void setQuery(const QString &itemId);

private slots:
   void updateIngredientDetail(const QString &indgredientDetailsId);

signals:
   void orderNumberChanged();
   void itemNameChanged();

private:
   void selectNextIngredientToPack();

   int m_orderNumber;
   QString m_itemName;

    RetrieveWebAppData *dataPage;

    QList<IngredientsPtr> m_ingredientsList;

    QList<QSharedPointer<IngredientDetailViewModel> > m_detailsModel;

    static const QString IngredientViewQuery;
    static const QString TAG;
};

#endif // INGREDIENTVIEWMODEL_H
