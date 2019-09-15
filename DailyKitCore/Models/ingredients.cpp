#include "ingredients.h"

Ingredients::Ingredients() :
    m_ingredientDetails(new IngredientDetails)
{
    registerTypes();
}

Ingredients::Ingredients(const Ingredients &ingredient)
{
    this->m_ingredientId = ingredient.m_ingredientId;
    this->m_ingredientSlipName = ingredient.m_ingredientSlipName;
    this->m_ingredientDetails = ingredient.m_ingredientDetails;

}

Ingredients::~Ingredients()
{

}

void Ingredients::registerTypes()
{
    qRegisterMetaType<Ingredients>("Ingredients");
    qRegisterMetaType<IngredientDetails>("IngredientDetails");

}


void Ingredients::setIngredientId(const QString ingredientId)
{
    m_ingredientId = ingredientId;
}


QString Ingredients::ingredientId() const
{
    return m_ingredientId;
}


void Ingredients::setIngredientName(const QString ingredientName)
{
    m_ingredientSlipName = ingredientName;
}


QString Ingredients::ingredientName() const
{
    return m_ingredientSlipName;
}


void Ingredients::setIngredientDetail(const IngredientDetailsPtr ingredientDetails)
{
    m_ingredientDetails = ingredientDetails;
}


IngredientDetailsPtr Ingredients::ingredientDetails()
{
    return m_ingredientDetails;
}

