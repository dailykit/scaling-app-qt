#ifndef PLANDETAILS_H
#define PLANDETAILS_H
#include <QString>
#include <QSharedPointer>

struct IngredientProcess {
    QString m_ingredientProcess;
    int m_ingredientProcessWeight;
    int m_ingredientProcessCount;
    int m_ingredientPackedCount;

    IngredientProcess() :
        m_ingredientProcessWeight(0),
        m_ingredientProcessCount(0),
        m_ingredientPackedCount(0)
    {
    }

    IngredientProcess(const IngredientProcess &process) :
        m_ingredientProcess(process.m_ingredientProcess),
        m_ingredientProcessWeight(process.m_ingredientProcessWeight),
        m_ingredientProcessCount(process.m_ingredientProcessCount),
        m_ingredientPackedCount(process.m_ingredientPackedCount)
    {
    }

    ~IngredientProcess() {}

    IngredientProcess &operator =(IngredientProcess &process) {
        m_ingredientProcess = process.m_ingredientProcess;
        m_ingredientProcessWeight = process.m_ingredientProcessWeight;
        m_ingredientProcessCount = process.m_ingredientProcessCount;
        m_ingredientPackedCount = process.m_ingredientPackedCount;

        return *this;
    }
};
typedef  QSharedPointer<IngredientProcess> IngredientProcessPtr;

class PlanDetails
{
public:
    explicit PlanDetails();
    PlanDetails(const PlanDetails &plan);
    PlanDetails &operator = (PlanDetails &details);
    ~PlanDetails();
    void registerTypes();

    /**
     * @brief setIngredientId - ingredient Id for the planning view
     * @param ingredientID - QString
     */
    void setIngredientId(QString ingredientID);

    /**
     * @brief ingredientID - get the ingredient id
     * @return - QString
     */
    QString ingredientID()const;

    /**
     * @brief setIngredientName - set the ingredient name
     * @param name - QString
     */
    void setIngredientName(QString name);

    /**
     * @brief ingredientName - get ingredient name
     * @return - QString
     */
    QString ingredientName() const;

    /**
     * @brief ingredientTotalWeight - set ingredient total weight
     * @param weight
     */
    void setIngredientTotalWeight(int weight);

    /**
     * @brief ingredientTotalWeight - ingredient total weight
     * @return - int
     */
    int ingredientTotalWeight() const;

private:
    QString m_ingredientDetailId;
    QString m_ingredientName;
    int m_ingredientTotalWeight;

};
Q_DECLARE_METATYPE(IngredientProcess)
Q_DECLARE_METATYPE(PlanDetails)
typedef QSharedPointer<PlanDetails> PlanningPtr;

#endif // PLANDETAILS_H
