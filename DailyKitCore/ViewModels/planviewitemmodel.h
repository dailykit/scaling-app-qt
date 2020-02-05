#ifndef PLANVIEWITEMMODEL_H
#define PLANVIEWITEMMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QSqlQuery>
#include "../Models/planitemdetails.h"
#include <QDebug>

class PlanViewItemModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(float totalWeight READ totalWeight WRITE setTotalWeight NOTIFY totalWeightChanged)
    Q_PROPERTY(QString ingredientName READ ingredientName WRITE setIngredientName NOTIFY ingredientNameChanged)

    enum PlanItems {
        OrderId,
        ItemsId,
        IngredientId,
        IngredientDetailId,
        ItemName,
        IngredientWeight
    };

public:
    explicit PlanViewItemModel(QObject *parent = nullptr);
    virtual ~PlanViewItemModel() override;

    float totalWeight() const;
    void setTotalWeight(float weight);

    QString ingredientName() const;
    void setIngredientName(QString ingredient);


    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    Q_INVOKABLE void getItems(QString ingredientProcess, QString ingredientName, float totalWeight);

signals:
    void ingredientNameChanged();
    void totalWeightChanged();

private:
    QString m_ingredientName;
    float m_totalWeight;
    QList <PlanItemDetailsPtr> m_planItemDetailsList;
};

#endif // PLANVIEWITEMMODEL_H
