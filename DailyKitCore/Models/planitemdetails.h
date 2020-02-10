#ifndef PLANITEMDETAILS_H
#define PLANITEMDETAILS_H

#include <QObject>
#include <QString>

class PlanItemDetails
{
public:
    explicit PlanItemDetails();
    ~PlanItemDetails();

    /**
     * @brief setIngredientId - set ingredient Id for each detail ingredient
     * @param ingredientId - QString
     */
    void setIngredientId(const QString ingredientId);

    /**
     * @brief ingredientId - ingredient id
     * @return - QString
     */
    QString ingredientId() const;

    /**
     * @brief setItemId - set the item id
     * @param itemId - QString
     */
    void setItemId(const QString itemId);

    /**
     * @brief itemId - get the item id for process
     * @return - QString
     */
    QString itemId() const;

    /**
     * @brief setOrderId - set order id
     * @param orderId - QString
     */
    void setOrderId(const QString orderId);

    /**
     * @brief orderId - get the order id
     * @return - QString
     */
    QString orderId() const;

    /**
     * @brief setItemName - set the item name
     * @param item - QString
     */
    void setItemName(QString item);


    /**
     * @brief itemName - item name
     * @return QString
     */
    QString itemName() const;

    /**
     * @brief setIngredientWeight - set the ingredient weight
     * @param ingredientWeight - int
     */
    void setIngredientWeight(float ingredientWeight);

    /**
     * @brief ingredientWeight - get ingredient weight
     * @return - int
     */
    float ingredientWeight() const;

    /**
     * @brief setIngredientDetailId - set the ingredient details id
     * @param detailId
     */
    void setIngredientDetailId(QString detailId);

    /**
     * @brief ingredientDetailId - get ingredient details id
     * @return
     */
    QString ingredientDetailId() const;


private:
    //QString m_ingredientId;
    QString m_itemId;
    QString m_orderId;
    QString m_itemName;
    QString m_ingredientDetailId;
    QString m_ingredientId;
    float m_ingredientWeight;

};

Q_DECLARE_METATYPE(PlanItemDetails)
typedef  QSharedPointer<PlanItemDetails> PlanItemDetailsPtr;

#endif // PLANITEMDETAILS_H
