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
    Q_PROPERTY(float calculatedQuantity READ calculatedQuantity WRITE setCalculatedQuantity NOTIFY calculatedQuantityChanged)
    Q_PROPERTY(QString ingredientStatus READ ingredientStatus WRITE setIngredientStatus NOTIFY ingredientStatusChanged)
    Q_PROPERTY(QString scaleStatus READ scaleStatus WRITE setScaleStatus NOTIFY scaleStatusChanged)
    Q_PROPERTY(QString ingredientWeightString READ ingredientWeightString WRITE setIngredientWeightString NOTIFY ingredientWeightStringChanged)

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

    float calculatedQuantity()const;
    void setCalculatedQuantity(const float itemWeight);

    QString weight() const;
    void setWeight(const QString grams);

    QString ingredientStatus();
    void setIngredientStatus(QString status);

    QString scaleStatus() const;
    void setScaleStatus(QString status);

    QString ingredientWeightString() const;
    void setIngredientWeightString(const QString weight);

    Q_INVOKABLE float ingredientQuantity() const;

    static WeighingScaleModel *weighScaleInstance();



signals:
    void orderIdChanged();
    void itemNameChanged();
    void ingredientNameChanged();
    void calculatedQuantityChanged();
    void weightChanged();
    void weightRangeChanged();
    void ingredientStatusChanged();
    void scaleStatusChanged();
    void ingredientWeightStringChanged();

public slots:
    Q_INVOKABLE void calculateActualWeight(float quantity);
    Q_INVOKABLE void weighItem(QString ingredientId, QString ingredientName, float quantity, QString weight);
    Q_INVOKABLE void weightAccuracy(float accuracy);
    Q_INVOKABLE void setTearWeight(float tearWeight);
    Q_INVOKABLE float tearWeight() const;
private slots:
    void ingredientPacked();
    void checkIfIngredientInWeightRange(float quantity);
private:
    explicit WeighingScaleModel(QObject *parent = nullptr);

    QString m_ingredientName;
    QString m_itemName;
    QString m_orderId;
    QString m_ingredientDetailId;
    QString m_ingredientWeight;
    QString m_ingredientStatus;
    QString m_scaleStatus;
    QString m_ingredientWeightString; // used to show on the weighing scale on qml
    float m_ingredientCalculatedWeight;
    float m_ingredientQuantity;
    float m_weighAccuracyRange;
    float m_tearWeight;
    IngredientWeight m_weightRange;

    static const QString WEIGHINGSTATUS[];
    static const QString SCALESTATUS[];

    static WeighingScaleModel * m_weighingScaleModel;


    QTimer* m_ingredientPackedTimer;
};

#endif // WEIGHINGSCALEMODEL_H
