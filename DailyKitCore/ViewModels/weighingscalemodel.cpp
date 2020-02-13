#include "weighingscalemodel.h"
#include <QDebug>
#include "../DatabaseModels/dbproxy.h"

WeighingScaleModel* WeighingScaleModel::m_weighingScaleModel = nullptr;

const QString WeighingScaleModel::WEIGHINGSTATUS[] = {
    "Start Weighing",
    "Status: Low",
    "Status: High",
    "Printing Label",
    "Status: Packed"
};

const QString WeighingScaleModel::SCALESTATUS[] = {
    "Ready",
    "Add",
    "Reduce"
};

WeighingScaleModel::WeighingScaleModel(QObject *parent) :
    QObject(parent),
    m_ingredientName("No Ingredient Selected"),
    m_itemName("No Item Selected"),
    m_orderId("No Order Selected"),
    m_ingredientStatus(WEIGHINGSTATUS[0]),
    m_scaleStatus(SCALESTATUS[0]),
    m_ingredientCalculatedWeight(0),
    m_ingredientQuantity(0),
    m_weighAccuracyRange(0),
    m_weightRange(UnderWeight),
    m_ingredientPackedTimer(new QTimer(this))
{
    if(m_ingredientPackedTimer != nullptr) {
        m_ingredientPackedTimer->setInterval(3000);
        m_ingredientPackedTimer->setSingleShot(true);
        connect(m_ingredientPackedTimer, &QTimer::timeout, this, &WeighingScaleModel::ingredientPacked);
    }

}

WeighingScaleModel::IngredientWeight WeighingScaleModel::weightRange() const
{
    return m_weightRange;
}

void WeighingScaleModel::setWeightRange(WeighingScaleModel::IngredientWeight weight)
{
    m_weightRange = weight;
    emit weightRangeChanged();
}

QString WeighingScaleModel::orderId() const
{
    return  m_orderId;
}

void WeighingScaleModel::setOrderId(const QString id)
{
    m_orderId = id;
    emit orderIdChanged();
}

QString WeighingScaleModel::itemName() const
{
    return m_itemName;
}

void WeighingScaleModel::setItemName(const QString item)
{
    m_itemName = item;
    emit itemNameChanged();

}

QString WeighingScaleModel::ingredientName() const
{
    return m_ingredientName;
}

void WeighingScaleModel::setIngredientName(QString ingredient)
{
    m_ingredientName = ingredient;
    emit ingredientNameChanged();

}

float WeighingScaleModel::calculatedQuantity() const
{
    return m_ingredientCalculatedWeight;
}

void WeighingScaleModel::setCalculatedQuantity(const float itemWeight)
{
    m_ingredientCalculatedWeight = itemWeight;
    emit calculatedQuantityChanged();
}

QString WeighingScaleModel::weight() const
{
    return m_ingredientWeight.toLower();
}

void WeighingScaleModel::setWeight(const QString grams)
{
    m_ingredientWeight = grams;
    emit weightChanged();
}

QString WeighingScaleModel::ingredientStatus()
{
    return m_ingredientStatus;
}

void WeighingScaleModel::setIngredientStatus(QString status)
{
    qDebug() << "status" << status;
    m_ingredientStatus = status;
    emit ingredientStatusChanged();
}

QString WeighingScaleModel::scaleStatus() const
{
    return m_scaleStatus;
}

void WeighingScaleModel::setScaleStatus(QString status)
{
    m_scaleStatus  = status;
    emit scaleStatusChanged();
}

float WeighingScaleModel::ingredientQuantity() const
{
    return m_ingredientQuantity;
}

WeighingScaleModel *WeighingScaleModel::weighScaleInstance()
{
    if(m_weighingScaleModel == nullptr) {
        m_weighingScaleModel = new WeighingScaleModel();
    }
    return m_weighingScaleModel;
}

void WeighingScaleModel::calculateActualWeight(float quantity)
{
    setWeightRange(UnderWeight);
    setCalculatedQuantity(abs(quantity));
    checkIfIngredientInWeightRange(quantity);
}

void WeighingScaleModel::weighItem(QString ingredientDetailID, QString ingredientName, float quantity, QString weight)
{
    qDebug() << "Weighing" << weight << ingredientDetailID;
   // setOrderId(orderId);
    setIngredientName(ingredientName);
    setCalculatedQuantity(0);
    setWeight(weight);
    setIngredientStatus(WEIGHINGSTATUS[0]);
    setWeightRange(UnderWeight);
    m_ingredientDetailId = ingredientDetailID;
    m_ingredientQuantity = quantity ;
}

void WeighingScaleModel::weightAccuracy(float accuracy)
{
    m_weighAccuracyRange = accuracy;
}

void WeighingScaleModel::ingredientPacked()
{
    qDebug() << "timer set" << m_ingredientDetailId;
    DbProxy::dbInstance()->setIngredientAsWeighed(m_ingredientDetailId);
    setIngredientStatus(WEIGHINGSTATUS[4]);
}

void WeighingScaleModel::checkIfIngredientInWeightRange(float quantity)
{
    if(abs(ingredientQuantity() - quantity) >= 0 && abs(ingredientQuantity() - quantity) <= m_weighAccuracyRange) {
        setIngredientStatus(WEIGHINGSTATUS[3]);
        setWeightRange(WeightInRange);
        setScaleStatus(SCALESTATUS[0]);
        m_ingredientPackedTimer->start();
    } else if(quantity > ingredientQuantity()) {
        setIngredientStatus(WEIGHINGSTATUS[2]);
        QString state = SCALESTATUS[2] +  " " + QString::number(abs(ingredientQuantity() - quantity)) + " " + weight();
        setScaleStatus(state);
        setWeightRange(OverWeight);
    } else {
        QString state = SCALESTATUS[1] +  " " + QString::number(abs(ingredientQuantity() - quantity)) + " " + weight();
        setIngredientStatus(WEIGHINGSTATUS[1]);
        setScaleStatus(state);
    }

}


