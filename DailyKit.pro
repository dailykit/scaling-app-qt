QT += quick core network sql svg xml
CONFIG += c++11

QTPLUGIN += qtvirtualkeyboardplugin

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        DailyKitCore/DatabaseModels/dbmanager.cpp \
        DailyKitCore/DatabaseModels/dbproxy.cpp \
        DailyKitCore/External/WebServices/loginaccessmanager.cpp \
        DailyKitCore/Models/ingredients.cpp \
        DailyKitCore/Models/itemdetails.cpp \
        DailyKitCore/Models/orderdetails.cpp \
        DailyKitCore/Models/plandetails.cpp \
        DailyKitCore/Models/planitemdetails.cpp \
        DailyKitCore/ViewModels/ingredientdetailviewmodel.cpp \
        DailyKitCore/ViewModels/ingredientprocessmodel.cpp \
        DailyKitCore/ViewModels/ingredientviewmodel.cpp \
        DailyKitCore/ViewModels/itemviewmodel.cpp \
        DailyKitCore/ViewModels/loginhandler.cpp \
        DailyKitCore/ViewModels/mainviewmodel.cpp \
        DailyKitCore/ViewModels/manipulateingredients.cpp \
        DailyKitCore/ViewModels/orderviewmodel.cpp \
        DailyKitCore/External/WebServices/retrievewebappdata.cpp \
        DailyKitCore/ViewModels/planviewitemmodel.cpp \
        DailyKitCore/ViewModels/planviewmodel.cpp \
        DailyKitCore/ViewModels/recenttabsmodel.cpp \
        DailyKitCore/ViewModels/recenttabsplanview.cpp \
        DailyKitCore/ViewModels/settingsmodel.cpp \
        DailyKitCore/ViewModels/weighingscalemodel.cpp \
        main.cpp

RESOURCES += qml.qrc \
    font.qrc \
    images.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model


INCLUDEPATH +=
INCLUDEPATH += \                         # <-
    include \                            # <- Without these 3 lines the compile fails
    External \


# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    DailyKitCore/DatabaseModels/dbmanager.h \
    DailyKitCore/DatabaseModels/dbproxy.h \
    DailyKitCore/External/WebServices/loginaccessmanager.h \
    DailyKitCore/Models/ingredients.h \
    DailyKitCore/Models/itemdetails.h \
    DailyKitCore/Models/orderdetails.h \
    DailyKitCore/Models/plandetails.h \
    DailyKitCore/Models/planitemdetails.h \
    DailyKitCore/ViewModels/ingredientdetailviewmodel.h \
    DailyKitCore/ViewModels/ingredientprocessmodel.h \
    DailyKitCore/ViewModels/ingredientviewmodel.h \
    DailyKitCore/ViewModels/itemviewmodel.h \
    DailyKitCore/ViewModels/loginhandler.h \
    DailyKitCore/ViewModels/mainviewmodel.h \
    DailyKitCore/ViewModels/manipulateingredients.h \
    DailyKitCore/ViewModels/orderviewmodel.h \
    DailyKitCore/External/WebServices/retrievewebappdata.h \
    DailyKitCore/ViewModels/planviewitemmodel.h \
    DailyKitCore/ViewModels/planviewmodel.h \
    DailyKitCore/ViewModels/recenttabsmodel.h \
    DailyKitCore/ViewModels/recenttabsplanview.h \
    DailyKitCore/ViewModels/settingsmodel.h \
    DailyKitCore/ViewModels/weighingscalemodel.h \

android {
DISTFILES += \
    android/AndroidManifest.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew \
    android/gradlew.bat \
    android/res/values/libs.xml

contains(ANDROID_TARGET_ARCH,armeabi-v7a) {
    ANDROID_PACKAGE_SOURCE_DIR = \
        $$PWD/android
}
}
