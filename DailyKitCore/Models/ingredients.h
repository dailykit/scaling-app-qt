/******************************************************
 * This class keeps the details of the ingredients required to prepare
 * for each dish, it also holds the list of sub ingredients and it informations;
 *******************************************************/


#ifndef INGREDIENTDETAILS_H
#define INGREDIENTDETAILS_H

#include <QList>
#include <QMetaType>
#include <QSharedPointer>
#include <QString>

struct IngredientDetails {

    Q_GADGET

    Q_PROPERTY(int isIngredientPacked MEMBER m_isIngredientPacked)
    Q_PROPERTY(QString ingredientDetailId MEMBER m_ingredientDetailId)
    Q_PROPERTY(QString ingredientName MEMBER m_ingredientName)
    Q_PROPERTY(QString ingredientQuantity MEMBER m_ingredientQuantity)
    Q_PROPERTY(QString ingredientMeasure MEMBER m_ingredientMeasure)
    Q_PROPERTY(QString ingredientProcess MEMBER m_ingredientProcess)

public:

    QString m_ingredientDetailId;
    QString m_ingredientName;
    QString m_ingredientQuantity;
    QString m_ingredientMeasure;
    QString m_ingredientProcess;
    int m_isIngredientPacked;

    IngredientDetails():
    m_isIngredientPacked(0)
    {
    }

    IngredientDetails(const IngredientDetails &details) {
        this->m_ingredientDetailId = details.m_ingredientDetailId;
        this->m_ingredientName = details.m_ingredientName;
        this->m_ingredientQuantity = details.m_ingredientQuantity;
        this->m_ingredientMeasure = details.m_ingredientMeasure;
        this->m_ingredientProcess = details.m_ingredientProcess;
        this->m_isIngredientPacked = details.m_isIngredientPacked;
    }
    ~IngredientDetails() {}
};

typedef QSharedPointer<IngredientDetails> IngredientDetailsPtr;



class Ingredients
{

public:
    explicit Ingredients();
    Ingredients(const Ingredients & ingredient);
    virtual ~Ingredients();

    void registerTypes();

    /**
     * @brief setIngredientId - set the ingredient id of an item in a particular order
     * @param ingredientId - QString
     */
    void setIngredientId(const QString ingredientId);

    /**
     * @brief ingredientId - gives the ingredient id of an item in a particular order
     * @return - QString
     */
    QString ingredientId() const;

    /**
     * @brief setIngredientName - set the ingredient name of an item in a particular order
     * @param ingredientName
     */
    void setIngredientName(const QString ingredientName);

    /**
     * @brief ingredientName - set the name of the ingredient of an item in a particular order
     * @return - QString
     */
    QString ingredientName() const;

    /**
     * @brief setIngredientDetail -  sets the list of the details of the ingredients of an item
     * @param ingredientDetails - QList<IngredientDetails*>
     */
    void setIngredientDetail(const IngredientDetailsPtr ingredientDetails);

    /**
     * @brief ingredientDetails - gives the list of details about an ingredient of an item
     * @return ingredient details pointer
     */
    IngredientDetailsPtr ingredientDetails() const;

//    /**
//     * @brief setIngredientDetailCount - set the ingredient details count of a particular ingredient
//     * @param count - intS
//     */
//    void setIngredientDetailCount(const int count);

//    /**
//     * @brief ingredientDetailCount - gives the count of details of an ingredients
//     * @return - int
//     */
//    int ingredientDetailCount();

private:
    QString m_ingredientId;
    QString m_ingredientSlipName;
  //  int m_ingredientsDetailsCount;
    IngredientDetailsPtr m_ingredientDetails;


};

Q_DECLARE_METATYPE(Ingredients)
Q_DECLARE_METATYPE(IngredientDetails)
Q_DECLARE_METATYPE(QList<IngredientDetails*>)
typedef  QSharedPointer<Ingredients> IngredientsPtr;

#endif // INGREDIENTDETAILS_H
