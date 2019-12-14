#include <QGuiApplication>
#include <QQuickView>
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <QQmlContext>
#include "DailyKitCore/External/WebServices/retrievewebappdata.h"
#include "DailyKitCore/DatabaseModels/dbmanager.h"
#include "DailyKitCore/ViewModels/orderviewmodel.h"
#include "DailyKitCore/ViewModels/ingredientviewmodel.h"
#include "DailyKitCore/ViewModels/weighingscalemodel.h"
#include "DailyKitCore/ViewModels/recenttabsmodel.h"
#include "DailyKitCore/ViewModels/itemviewmodel.h"
#include "DailyKitCore/ViewModels/planviewmodel.h"
#include "DailyKitCore/ViewModels/planviewitemmodel.h"
#include "DailyKitCore/ViewModels/settingsmodel.h"
#include "DailyKitCore/DatabaseModels/dbproxy.h"


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);


    QCoreApplication::setOrganizationName("Scaling");
    QCoreApplication::setApplicationName("DailyKit");

    DBManager::connectToDatabase();
    //DbProxy::dbInstance();

    OrderViewModel *m_model = new OrderViewModel();

    IngredientViewModel* m_ingredient = new IngredientViewModel();
    RecentTabsModel *m_recentTabs = new RecentTabsModel();
    ItemViewModel *m_itemsModel = new ItemViewModel();
    SettingsModel *m_settingsModel = new SettingsModel();
    PlanViewModel * m_plan = new PlanViewModel();
    PlanViewItemModel *m_planningItems = new PlanViewItemModel();

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("orderModel", m_model);
    engine.rootContext()->setContextProperty("ingredientModel", m_ingredient);
    engine.rootContext()->setContextProperty("recentTabs", m_recentTabs);
    engine.rootContext()->setContextProperty("itemsModel", m_itemsModel);
    engine.rootContext()->setContextProperty("settingsModel", m_settingsModel);
    engine.rootContext()->setContextProperty("planModel", m_plan);
    engine.rootContext()->setContextProperty("planningItems", m_planningItems);

    engine.rootContext()->setContextProperty("weighingScale", WeighingScaleModel::weighScaleInstance());

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));


    return app.exec();
}



