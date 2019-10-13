#ifndef WEIGHINGSCALEMODEL_H
#define WEIGHINGSCALEMODEL_H

#include <QObject>

class WeighingScaleModel : public QObject
{
    Q_OBJECT
    Q_ENUMS(IngredientWeight)



    Q_PROPERTY(IngredientWeight weightRange READ weightRange WRITE setWeightRange NOTIFY weightRangeChanged)
    Q_PROPERTY(QString orderId READ orderId WRITE setOrderId NOTIFY orderIdChanged)
    Q_PROPERTY(QString itemName READ itemName WRITE setItemName NOTIFY itemNameChanged)
    Q_PROPERTY(QString ingredientName READ ingredientName WRITE setIngredientName NOTIFY ingredientNameChanged)
    Q_PROPERTY(QString weight READ weight WRITE setWeight NOTIFY weightChanged)
    Q_PROPERTY(int calculatedQuantity READ calculatedQuantity WRITE setCalculatedQuantity NOTIFY calculatedQuantityChanged)

public:
    explicit WeighingScaleModel(QObject *parent = nullptr);


    enum IngredientWeight {
        UnderWeight = 0,
        WeightInRange,
        OverWeight,
        MaxIngredientWeight //always add new enum above this
    };

    IngredientWeight weightRange() const;
    void setWeightRange(IngredientWeight weight);

    QString orderId() const;
    void setOrderId(const QString id);

    QString itemName() const;
    void setItemName(const QString item);

    QString ingredientName() const;
    void setIngredientName(QString ingredient);

    int calculatedQuantity()const;
    void setCalculatedQuantity(const int itemWeight);

    QString weight() const;
    void setWeight(const QString grams);

    Q_INVOKABLE int ingredientQuantity() const;


signals:
    void orderIdChanged();
    void itemNameChanged();
    void ingredientNameChanged();
    void calculatedQuantityChanged();
    void weightChanged();
    void weightRangeChanged();

public slots:
    Q_INVOKABLE void calculateActualWeight(int quantity);
    Q_INVOKABLE void weighItem(QString ingredientId, QString itemName, QString ingredientName, int quantity, QString weight);

private:
    QString m_ingredientName;
    QString m_itemName;
    QString m_orderId;
    QString m_ingredientId;
    QString m_ingredientWeight;
    int m_ingredientCalculatedWeight;
    int m_ingredientQuantity;
    IngredientWeight m_weightRange;

};

#endif // WEIGHINGSCALEMODEL_H
