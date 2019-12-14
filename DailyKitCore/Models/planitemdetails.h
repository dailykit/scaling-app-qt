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


private:
    //QString m_ingredientId;
    QString m_itemId;
    QString m_orderId;
    QString m_itemName;
    float m_ingredientWeight;
};

Q_DECLARE_METATYPE(PlanItemDetails)
typedef  QSharedPointer<PlanItemDetails> PlanItemDetailsPtr;

#endif // PLANITEMDETAILS_H
