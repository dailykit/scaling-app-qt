#include <QGuiApplication>
#include <QFontDatabase>
#include <QQuickView>
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <QQmlContext>
#include "DailyKitCore/External/WebServices/retrievewebappdata.h"
#include "DailyKitCore/DatabaseModels/dbmanager.h"
#include "DailyKitCore/ViewModels/mainviewmodel.h"
#include "DailyKitCore/ViewModels/ingredientviewmodel.h"
#include "DailyKitCore/ViewModels/weighingscalemodel.h"
#include "DailyKitCore/ViewModels/recenttabsmodel.h"
#include "DailyKitCore/ViewModels/itemviewmodel.h"
#include "DailyKitCore/ViewModels/planviewmodel.h"
#include "DailyKitCore/ViewModels/planviewitemmodel.h"
#include "DailyKitCore/ViewModels/settingsmodel.h"
#include "DailyKitCore/ViewModels/loginhandler.h"
#include "DailyKitCore/DatabaseModels/dbproxy.h"
#include "DailyKitCore/External/WebServices/loginaccessmanager.h"
#include <QFileInfo>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);


    QCoreApplication::setOrganizationName("Scaling");
    QCoreApplication::setApplicationName("DailyKit");
    QQmlApplicationEngine engine;

    LoginHandler* m_login = new LoginHandler;
    engine.rootContext()->setContextProperty("loginAccess", m_login);

    DBManager::connectToDatabase();
    //DbProxy::dbInstance();



    MainViewModel *m_model = new MainViewModel();

    IngredientViewModel* m_ingredient = new IngredientViewModel();
    RecentTabsModel *m_recentTabs = new RecentTabsModel();
    ItemViewModel *m_itemsModel = new ItemViewModel();
    SettingsModel *m_settingsModel = new SettingsModel();
    PlanViewModel * m_plan = new PlanViewModel();
    PlanViewItemModel *m_planningItems = new PlanViewItemModel();


    engine.rootContext()->setContextProperty("mainModel", m_model);
    engine.rootContext()->setContextProperty("orderModel", m_model->getOrdersModel());
    engine.rootContext()->setContextProperty("ingredientModel", m_ingredient);
    engine.rootContext()->setContextProperty("recentTabs", m_recentTabs);
    engine.rootContext()->setContextProperty("itemsModel", m_itemsModel);
    engine.rootContext()->setContextProperty("settingsModel", m_settingsModel);
    engine.rootContext()->setContextProperty("planModel", m_plan);
    engine.rootContext()->setContextProperty("planningItems", m_planningItems);
    engine.rootContext()->setContextProperty("weighingScale", WeighingScaleModel::weighScaleInstance());

    //Add font files
    qint32 fontId = QFontDatabase::addApplicationFont(QString(":/QML/Default/fonts/Roboto-Regular.ttf"));
    QString family = QFontDatabase::applicationFontFamilies(fontId).at(0);

    app.setFont(QFont(family));


    //load the main QML
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));


    return app.exec();
}



