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

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    DBManager::connectToDatabase();

    OrderViewModel *m_model = new OrderViewModel();
//    RetrieveWebAppData *webData = new RetrieveWebAppData();
//    webData->getOrderList();

    IngredientViewModel* m_ingredient = new IngredientViewModel();
    WeighingScaleModel *m_weighingScale = new WeighingScaleModel();
    RecentTabsModel *m_recentTabs = new RecentTabsModel();

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("orderModel", m_model);
    engine.rootContext()->setContextProperty("ingredientModel", m_ingredient);
    engine.rootContext()->setContextProperty("weighingScale", m_weighingScale);
    engine.rootContext()->setContextProperty("recentTabs", m_recentTabs);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));


    return app.exec();
}



