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
#include "DailyKitCore/DatabaseModels/dbproxy.h"


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    DBManager::connectToDatabase();
    //DbProxy::dbInstance();

    OrderViewModel *m_model = new OrderViewModel();
//    RetrieveWebAppData *webData = new RetrieveWebAppData();
//    webData->getOrderList();

    IngredientViewModel* m_ingredient = new IngredientViewModel();
    RecentTabsModel *m_recentTabs = new RecentTabsModel();

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("orderModel", m_model);
    engine.rootContext()->setContextProperty("ingredientModel", m_ingredient);
    engine.rootContext()->setContextProperty("recentTabs", m_recentTabs);

    engine.rootContext()->setContextProperty("weighingScale", WeighingScaleModel::weighScaleInstance());

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));


    return app.exec();
}



