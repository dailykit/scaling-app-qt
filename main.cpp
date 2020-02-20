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
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));
    QGuiApplication app(argc, argv);


    QCoreApplication::setOrganizationName("Scaling");
    QCoreApplication::setApplicationName("DailyKit");
    QQmlApplicationEngine engine;

    LoginHandler* m_login = new LoginHandler;
    engine.rootContext()->setContextProperty("loginAccess", m_login);

    DBManager::connectToDatabase();

    MainViewModel *m_model = new MainViewModel();

    engine.rootContext()->setContextProperty("mainModel", m_model);


    //Add font files
    qint32 fontId = QFontDatabase::addApplicationFont(QString(":/QML/Default/fonts/Roboto-Regular.ttf"));
    QString family = QFontDatabase::applicationFontFamilies(fontId).at(0);

    app.setFont(QFont(family));


    //load the main QML
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));


    return app.exec();
}



