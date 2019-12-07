#ifndef INGREDIENTPROCESSMODEL_H
#define INGREDIENTPROCESSMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include "../Models/plandetails.h"

class IngredientProcessModel : public QAbstractListModel
{

    enum {
        IngredientId,
        IngredientQuantity,
        IngredientProcessName,
        IngredientPackedCount,
        IngredientProcessCount
    };

public:
    IngredientProcessModel(QObject *parent = nullptr);

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    void setIngredientProcess(IngredientProcessPtr details);
    QList <IngredientProcessPtr> ingredientProcessList();

private:
    QList <IngredientProcessPtr> m_ingredientProcessList;

};

#endif // INGREDIENTPROCESSMODEL_H
