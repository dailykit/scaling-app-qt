#ifndef INGREDIENTPROCESSMODEL_H
#define INGREDIENTPROCESSMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include "../Models/plandetails.h"

class IngredientProcessModel : public QAbstractListModel
{
    Q_OBJECT

    enum {
        IngredientId,
        IngredientQuantity,
        IngredientProcessName,
        IngredientPackedCount,
        IngredientProcessCount,
        CurrentItem
    };

    Q_PROPERTY(QString currentItem READ currentItem WRITE setCurrentItem NOTIFY currentItemChanged)

public:
    IngredientProcessModel(QObject *parent = nullptr);

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    void setIngredientProcess(IngredientProcessPtr details);
    QList <IngredientProcessPtr> ingredientProcessList();

   Q_INVOKABLE void setCurrentItem(QString ingredientProcess);
    QString currentItem() const;

signals:
    void currentItemChanged();

private:
    QList <IngredientProcessPtr> m_ingredientProcessList;
    QString m_currentItem;

};

#endif // INGREDIENTPROCESSMODEL_H
