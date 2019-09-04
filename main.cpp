#include <QGuiApplication>
#include <QQuickView>
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <QQmlContext>
#include "DailyKitCore/External/WebServices/retrievewebappdata.h"
#include "DailyKitCore/DatabaseModels/dbmanager.h"
#include "DailyKitCore/ViewModels/orderviewmodel.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    DBManager::connectToDatabase();

    OrderViewModel *m_model = new OrderViewModel();
    RetrieveWebAppData *webData = new RetrieveWebAppData();
    webData->getOrderList();

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("orderView", m_model);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));




    return app.exec();
}



