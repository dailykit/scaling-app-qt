#include "weighingscalemodel.h"
#include <QDebug>
#include "../DatabaseModels/dbproxy.h"

WeighingScaleModel* WeighingScaleModel::m_weighingScaleModel = nullptr;

WeighingScaleModel::WeighingScaleModel(QObject *parent) :
    QObject(parent),
    m_ingredientName("No Ingredient Selected"),
    m_itemName("No Item Selected"),
    m_orderId("No Order Selected"),
    m_ingredientStatus("Start Weighing"),
    m_ingredientCalculatedWeight(0),
    m_ingredientQuantity(0),
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

int WeighingScaleModel::calculatedQuantity() const
{
    return m_ingredientCalculatedWeight;
}

void WeighingScaleModel::setCalculatedQuantity(const int itemWeight)
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

QString WeighingScaleModel::ingredientStatus() const
{
    return m_ingredientStatus;
}

void WeighingScaleModel::setIngredientStatus(const QString status)
{
    m_ingredientStatus = status;
    emit ingredientStatusChanged();
}

int WeighingScaleModel::ingredientQuantity() const
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

void WeighingScaleModel::calculateActualWeight(int quantity)
{

    setCalculatedQuantity(quantity);
    setWeightRange(WeightInRange);
    m_ingredientPackedTimer->start();

}

void WeighingScaleModel::weighItem(QString ingredientId, QString ingredientName, float quantity, QString weight)
{
    qDebug() << "Weighing" << weight << ingredientId;
   // setOrderId(orderId);
    setIngredientName(ingredientName);
    setCalculatedQuantity(0);
    setWeight(weight);
    setIngredientStatus("Start Weighing");
    setWeightRange(UnderWeight);
    m_ingredientId = ingredientId;
    m_ingredientQuantity = quantity ;
}

void WeighingScaleModel::ingredientPacked()
{

    qDebug() << "timer set" << m_ingredientId;
    DbProxy::dbInstance()->setIngredientAsPacked(m_ingredientId);
    setIngredientStatus("Packed");

}


