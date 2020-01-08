#include "planviewmodel.h"
#include <QDebug>

PlanViewModel::PlanViewModel(QObject *parent) :
    QAbstractListModel(parent)
{
    getIngredients();
}

PlanViewModel::~PlanViewModel()
{

}

QVariant PlanViewModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= m_planningViewList.count())
    {
        return QVariant();

    }
    switch (role) {
    case IngredientId:
        return m_planningViewList[index.row()]->ingredientID();
    case IngredientName:
        return m_planningViewList[index.row()]->ingredientName();
    case IngredientQuantity:
        return m_planningViewList[index.row()]->ingredientTotalWeight();
    case IngredientProcessList:
        return QVariant::fromValue(m_processListModel[index.row()]);
    default:
        return QVariant();
    }
}


QHash<int, QByteArray> PlanViewModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles.insert(IngredientId, "ingredientId");
    roles.insert(IngredientName, "ingredientName");
    roles.insert(IngredientQuantity, "ingredientTotalWeight");
    roles.insert(IngredientProcessList, "processList");

    return roles;

}

int PlanViewModel::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid())
        return 0;

    return m_planningViewList.count();
}

void PlanViewModel::getIngredients()
{
    QSqlQuery query;
    if(query.exec("SELECT DISTINCT(ingredientName) FROM ingredientDetails "))
    {
        while (query.next()) {
            QSqlQuery processQuery, totalWeightQuery;
            processQuery.prepare("SELECT DISTINCT(ingredientProcess) FROM ingredientDetails WHERE ingredientName = ? ");
            processQuery.addBindValue(query.value(0).toString());
            processQuery.exec();

            PlanningPtr ptr(new PlanDetails());
            ptr->setIngredientName(query.value(0).toString());

            QSharedPointer<IngredientProcessModel> model(new IngredientProcessModel());
            while(processQuery.next())
            {

                QSqlQuery q2;
                q2.prepare("SELECT COUNT(ingredientProcess), SUM(ingredientQuantity), SUM(isPacked)"
                           " FROM ingredientDetails WHERE ingredientName = ? AND ingredientProcess=? ");
                q2.addBindValue(query.value(0).toString());
                q2.addBindValue(processQuery.value(0).toString());
                q2.exec();

                IngredientProcessPtr process(new IngredientProcess());
                process->m_ingredientProcess = processQuery.value(0).toString();

                while(q2.next()){
                    process->m_ingredientProcessWeight = q2.value(1).toInt();
                    process->m_ingredientProcessCount = q2.value(0).toInt();
                    process->m_ingredientPackedCount = q2.value(2).toInt();
                }
                model->setIngredientProcess(process);
            }

            totalWeightQuery.prepare("SELECT SUM(ingredientQuantity) FROM ingredientDetails WHERE ingredientName = ? ");
            totalWeightQuery.addBindValue(query.value(0).toString());
            totalWeightQuery.exec();
            while(totalWeightQuery.next()) {
                ptr->setIngredientTotalWeight(totalWeightQuery.value(0).toInt());
            }
            m_processListModel.append(model);
            m_planningViewList.append(ptr);
        }

    } else {
        qDebug() << "query failed";
    }
}
