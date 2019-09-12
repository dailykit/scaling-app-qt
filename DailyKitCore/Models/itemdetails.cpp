#include "itemdetails.h"

ItemDetails::ItemDetails() :
m_ingredientCount(0),
m_totalPackedIngredients(0)
{

}

ItemDetails::ItemDetails(const ItemDetails &item)
{
    this->m_orderId = item.m_orderId;
    this->m_itemOrderId = item.m_itemOrderId;
    this->m_recipeName = item.m_recipeName;
    this->m_orderStatus = item.m_orderStatus;
    this->m_recipeServings = item.m_recipeServings;
    this->m_ingredientCount = item.m_ingredientCount;
    this->m_totalPackedIngredients = item.m_totalPackedIngredients;
}

ItemDetails::~ItemDetails()
{

}

void ItemDetails::setOrderId(const QString order)
{
    m_orderId = order;

}

QString ItemDetails::orderId() const
{
    return m_orderId;
}

void ItemDetails::setItemOrderId(const QString itemId)
{
    m_itemOrderId = itemId;

}

QString ItemDetails::itemOrderId() const
{
    return m_itemOrderId;
}

void ItemDetails::setOrderStatus(const QString status)
{
    m_orderStatus = status;
}

QString ItemDetails::orderStatus() const
{
    return m_orderStatus;
}

void ItemDetails::setRecipeName(const QString recipe)
{
    m_recipeName = recipe;
}

QString ItemDetails::recipeName() const
{
    return m_recipeName;
}

void ItemDetails::setRecipeServings(const QString serving)
{
    m_recipeServings = serving;
}

QString ItemDetails::recipeServings() const
{
    return m_recipeServings;
}

void ItemDetails::setIngredientCount(const int count)
{
    m_ingredientCount = count;
}

int ItemDetails::ingredientCount() const
{
    return m_ingredientCount;
}

void ItemDetails::setPackedIngredients(const int packedCount)
{
    m_totalPackedIngredients = packedCount;
}

int ItemDetails::packedIngredients() const
{
    return m_totalPackedIngredients;
}
