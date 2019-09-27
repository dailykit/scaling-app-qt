/******************************************************
 * This class holds the items of an order, each order can have multiple
 * items i.e. dishes in this case, this will help us manipulate data
 * related to the items
 * ****************************************************/

#ifndef ITEMDETAILS_H
#define ITEMDETAILS_H

#include <QObject>
#include <QMultiMap>
#include "ingredients.h"

class ItemDetails
{

public:
    ItemDetails();
    ItemDetails(const ItemDetails &item);
    virtual ~ItemDetails();

    /**
     * @brief setOrderId - set the order id of each item in the list of items
     * @param order - QString
     */
    void setOrderId(const QString order);

    /**
     * @brief orderId - gives the order id of an item
     * @return
     */
    QString orderId() const;

    /**
     * @brief setItemOrderId - set the item id for each item, this is unique each dish
     * @param itemId - QString
     */
    void setItemOrderId(const QString itemId);

    /**
     * @brief itemOrderId - gives the unique id of the item
     * @return - QString
     */
    QString itemOrderId() const;

    /**
     * @brief setOrderStatus -  set the curent status of the order
     * @param status - QString
     */
    void setOrderStatus(const QString status);

    /**
     * @brief orderStatus -  returns the current status of the order
     * @return - QString
     */
    QString orderStatus() const;

    /**
     * @brief setRecipeName - set the receipe name of the particular item
     * @param recipe - QString
     */
    void setRecipeName(const QString recipe);

    /**
     * @brief recipeName - gives the name of the recipe of the item
     * @return- QString
     */
    QString recipeName() const;

    /**
     * @brief setRecipeServings - servings of one particular dish(item)
     * @param serving
     */
    void setRecipeServings(const QString serving);

    /**
     * @brief recipeServings - gives the value of servings per dish
     * @return - QString
     */
    QString recipeServings() const;

    /**
     * @brief setIngredientCount - set the ingredient count of the item
     * @param count - int
     */
    void setIngredientCount(const int count);

    /**
     * @brief ingredientCount -  total ingredient count of the item
     * @return  - int
     */
    int ingredientCount() const;

    /**
     * @brief setPackedIngredients - total ingredients packed
     * @param packedCount -  int
     */
    void setPackedIngredients(const int packedCount);

    /**
     * @brief packedIngredients - gives the value of packed ingredients
     * @return - int
     */
    int packedIngredients() const;

    /**
     * @brief setOrderNumber - order number of the item
     * @param orderNumber - int
     */
    void setOrderNumber(const int orderNumber);

    /**
     * @brief orderNumber - gives the order number the item
     * @return
     */
    int orderNumber() const;



private:
    QString m_orderId;
    QString m_itemOrderId;
    QString m_orderStatus;
    QString m_recipeName;
    QString m_recipeServings;
    int m_ingredientCount;
    int m_totalPackedIngredients;
    int m_orderNumber;
};

Q_DECLARE_METATYPE(ItemDetails)
typedef QSharedPointer<ItemDetails> ItemDetailsPtr;

#endif // ITEMDETAILS_H
