#ifndef PLANVIEWMODEL_H
#define PLANVIEWMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QSqlQuery>
#include "../Models/plandetails.h"
#include "ingredientprocessmodel.h"

class PlanViewModel : public QAbstractListModel
{
    Q_OBJECT
    enum {
        IngredientId,
        IngredientName,
        IngredientQuantity,
        IngredientProcessList
    };

public:
    PlanViewModel(QObject *parent = nullptr);
    virtual ~PlanViewModel() override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

public slots:
     void getIngredients();

private:
    static const QString PlanViewQuery;

   QList<PlanningPtr> m_planningViewList;
   QList<QSharedPointer<IngredientProcessModel> > m_processListModel;
};

#endif // PLANVIEWMODEL_H
