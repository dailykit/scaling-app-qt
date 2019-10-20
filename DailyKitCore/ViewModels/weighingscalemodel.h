#ifndef WEIGHINGSCALEMODEL_H
#define WEIGHINGSCALEMODEL_H

#include <QObject>
#include <QTimer>

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
    Q_PROPERTY(QString ingredientStatus READ ingredientStatus WRITE setIngredientStatus NOTIFY ingredientStatusChanged)
public:


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

    QString ingredientStatus() const;
    void setIngredientStatus(const QString status);

    Q_INVOKABLE int ingredientQuantity() const;

    static WeighingScaleModel *weighScaleInstance();



signals:
    void orderIdChanged();
    void itemNameChanged();
    void ingredientNameChanged();
    void calculatedQuantityChanged();
    void weightChanged();
    void weightRangeChanged();
    void ingredientStatusChanged();

public slots:
    Q_INVOKABLE void calculateActualWeight(int quantity);
    Q_INVOKABLE void weighItem(QString ingredientId, QString ingredientName, float quantity, QString weight);

private slots:
    void ingredientPacked();
private:
    explicit WeighingScaleModel(QObject *parent = nullptr);

    QString m_ingredientName;
    QString m_itemName;
    QString m_orderId;
    QString m_ingredientId;
    QString m_ingredientWeight;
    QString m_ingredientStatus;
    int m_ingredientCalculatedWeight;
    float m_ingredientQuantity;
    IngredientWeight m_weightRange;

    static WeighingScaleModel * m_weighingScaleModel;


    QTimer* m_ingredientPackedTimer;
};

#endif // WEIGHINGSCALEMODEL_H
