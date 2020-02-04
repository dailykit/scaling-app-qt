#ifndef MAINVIEWMODEL_H
#define MAINVIEWMODEL_H

#include <QObject>
#include "orderviewmodel.h"
#include "manipulateingredients.h"
#include "recenttabsplanview.h"
#include "DailyKitCore/DatabaseModels/dbproxy.h"

class MainViewModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(ManipulateIngredients* manipulateIngredients READ manipulateIngredients NOTIFY manipulateIngredientsChanged)
    Q_PROPERTY(RecentTabsPlanView* recentIngredients READ recentIngredients NOTIFY recentIngredientsChanged)
public:
    explicit MainViewModel(QObject *parent = nullptr);

signals:
   void manipulateIngredientsChanged();
   void recentIngredientsChanged();

public slots:
    OrderViewModel *getOrdersModel();
    ManipulateIngredients* manipulateIngredients();
    RecentTabsPlanView *recentIngredients();

    Q_INVOKABLE void getOrders();

private:
    DbProxy *m_databaseProxy;
    OrderViewModel *m_orderModel;
    ManipulateIngredients *m_ingredientsManipulation;
    RecentTabsPlanView *m_recentPlanView;
};

#endif // MAINVIEWMODEL_H
