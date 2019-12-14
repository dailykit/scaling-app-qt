#include "planitemdetails.h"

PlanItemDetails::PlanItemDetails() :
    m_ingredientWeight(0.0)
{

}

PlanItemDetails::~PlanItemDetails()
{

}

void PlanItemDetails::setItemId(const QString itemId)
{
    m_itemId = itemId;
}

QString PlanItemDetails::itemId() const
{
    return m_itemId;
}

void PlanItemDetails::setOrderId(const QString orderId)
{
    m_orderId = orderId;
}

QString PlanItemDetails::orderId() const
{
    return m_orderId;
}

void PlanItemDetails::setItemName(QString item)
{
    m_itemName = item;
}

QString PlanItemDetails::itemName() const
{
    return m_itemName;
}

void PlanItemDetails::setIngredientWeight(float ingredientWeight)
{
    m_ingredientWeight = ingredientWeight;
}

float PlanItemDetails::ingredientWeight() const
{
    return m_ingredientWeight;
}
