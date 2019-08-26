#include <QGuiApplication>
#include <QQuickView>
#include <QQmlApplicationEngine>
#include "DailyKitCore/External/WebServices/retrievewebappdata.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
       engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

       RetrieveWebAppData *webData = new RetrieveWebAppData();

    return app.exec();
}
