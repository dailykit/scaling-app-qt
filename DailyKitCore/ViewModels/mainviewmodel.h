#ifndef MAINVIEWMODEL_H
#define MAINVIEWMODEL_H

#include <QObject>
#include "DailyKitCore/DatabaseModels/dbproxy.h"
#include "ingredientviewmodel.h"
#include "manipulateingredients.h"
#include "orderviewmodel.h"
#include "recenttabsplanview.h"
#include "recenttabsmodel.h"
#include "itemviewmodel.h"
#include "settingsmodel.h"
#include "planviewmodel.h"
#include "planviewitemmodel.h"
#include "weighingscalemodel.h"

class MainViewModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(ManipulateIngredients* manipulateIngredients READ manipulateIngredients NOTIFY manipulateIngredientsChanged)
    Q_PROPERTY(RecentTabsPlanView* recentIngredients READ recentIngredients NOTIFY recentIngredientsChanged)
    Q_PROPERTY(OrderViewModel* ordersViewModel READ ordersViewModel NOTIFY ordersViewModelChanged)
    Q_PROPERTY(IngredientViewModel* ingredientsModel READ ingredientsModel NOTIFY ingredientsModelChanged)
    Q_PROPERTY(RecentTabsModel* recentTabs READ recentTabs NOTIFY recentTabsChanged)
    Q_PROPERTY(ItemViewModel* itemsModel READ itemsModel NOTIFY itemsModelChanged)
    Q_PROPERTY(SettingsModel* settingsModel READ settingsModel NOTIFY settingsModelChanged)
    Q_PROPERTY(PlanViewModel* planViewModel READ planViewModel NOTIFY planViewModelChanged)
    Q_PROPERTY(PlanViewItemModel* planViewItemModel READ planViewItemModel NOTIFY planViewItemModelChanged)
    Q_PROPERTY(WeighingScaleModel* weighingScale READ weighingScale NOTIFY weighingScaleChanged)


public:
    explicit MainViewModel(QObject *parent = nullptr);

signals:
   void manipulateIngredientsChanged();
   void recentIngredientsChanged();
   void ordersViewModelChanged();
   void ingredientsModelChanged();
   void recentTabsChanged();
   void itemsModelChanged();
   void settingsModelChanged();
   void planViewModelChanged();
   void planViewItemModelChanged();
   void weighingScaleChanged();

public slots:
    ManipulateIngredients* manipulateIngredients();
    RecentTabsPlanView* recentIngredients();
    OrderViewModel* ordersViewModel();
    IngredientViewModel* ingredientsModel();
    RecentTabsModel* recentTabs();
    ItemViewModel* itemsModel();
    SettingsModel *settingsModel();
    PlanViewModel *planViewModel();
    PlanViewItemModel *planViewItemModel();
    WeighingScaleModel *weighingScale();

    Q_INVOKABLE void getOrders();

private:
    DbProxy *m_databaseProxy;
    OrderViewModel *m_orderModel;
    ManipulateIngredients *m_ingredientsManipulation;
    RecentTabsPlanView *m_recentPlanView;
    IngredientViewModel *m_ingredientsModel;
    RecentTabsModel* m_recentTabs;
    ItemViewModel* m_itemsModel;
    SettingsModel* m_settingsModel;
    PlanViewModel* m_planViewModel;
    PlanViewItemModel *m_planViewItemModel;
};

#endif // MAINVIEWMODEL_H
