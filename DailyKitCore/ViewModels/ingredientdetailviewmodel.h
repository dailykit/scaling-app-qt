#ifndef INGREDIENTDETAILVIEWMODEL_H
#define INGREDIENTDETAILVIEWMODEL_H

#include <QDebug>
#include <QMetaType>
#include "../Models/ingredients.h"
#include "DailyKitCore/External/WebServices/retrievewebappdata.h"


class IngredientDetailViewModel : public  QAbstractListModel
{
    Q_OBJECT

    enum MyRoles{
        IngredientDetailId,
        IngredientName,
        IngredientProcess,
        IngredientQuantity,
        IngredientWeight,
        IngredientIsPacked,
        IngredientDetailsCount
    };

public:
    explicit IngredientDetailViewModel(QObject *parent = nullptr);
    virtual ~IngredientDetailViewModel() override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

public slots:

    void setIngredientDetails(IngredientDetailsPtr details);

private:
   QList<IngredientDetailsPtr> m_ingredientsDetailsList;
};

#endif // INGREDIENTDETAILVIEWMODEL_H
