#include "plandetails.h"

PlanDetails::PlanDetails() :
    m_ingredientTotalWeight(0)
{
}

PlanDetails::PlanDetails(const PlanDetails &plan) :
    m_ingredientDetailId(plan.m_ingredientDetailId),
    m_ingredientName(plan.m_ingredientName),
    m_ingredientTotalWeight(plan.m_ingredientTotalWeight)
{
}

PlanDetails::~PlanDetails()
{
}

void PlanDetails::registerTypes()
{
    qRegisterMetaType<PlanDetails>("PlanDetails");
    qRegisterMetaType<IngredientProcess>("IngredientProcess");

}

void PlanDetails::setIngredientId(QString ingredientID)
{
    m_ingredientDetailId = ingredientID;
}

QString PlanDetails::ingredientID() const
{
    return m_ingredientDetailId;
}

void PlanDetails::setIngredientName(QString name)
{
    m_ingredientName = name;
}

QString PlanDetails::ingredientName() const
{
    return m_ingredientName;
}

void PlanDetails::setIngredientTotalWeight(int weight)
{
    m_ingredientTotalWeight = weight;
}

int PlanDetails::ingredientTotalWeight() const
{
    return m_ingredientTotalWeight;
}
