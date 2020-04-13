import QtQuick 2.0
import QtQuick.Controls 2.5


import "../ApplicationCore/Style"
import "../Components/Delegates"


Item {

    id: rootLogin
    height: parent.height
    width: parent.width

    Rectangle {
        color: "white"
        height: parent.height
        width: parent.width

        Rectangle {
            id: logoRect

            width: 40
            height: 40
            anchors {
                top: parent.top
                topMargin: 27
                left: parent.left
                leftMargin: 40
            }

            Image {
                id: logoImage
                anchors.fill: parent
                source: Images.logo
            }
        }


        GridView {
            id: landingView

            anchors.fill: parent
            //TODO : remove fixed sizes
            anchors.leftMargin: 120
            anchors.topMargin: 148
            cellWidth: 270; cellHeight: 191

            currentIndex: 0
            model: AppsList{}
            delegate: AppsDelegate {
                outerRectColor: model.appColor
                applicationText: model.name

                MouseArea {
                    id: appMouseArea
                    anchors.fill: parent

                    onReleased: {
                        if(!model.isWebApp) {
                            var component = Qt.createComponent(Qt.resolvedUrl(model.url))
                            if (component.status === Component.Ready) {
                                component.createObject(null,  {replace: true, destroyOnPop: true, width: stackView.width, height: stackView.height});
                              //  stackView.pop()
                                stackView.push(component)
                            }
                        }else {
//                            var component1 = Qt.createComponent(Qt.resolvedUrl("WebAppsPage.qml"))
//                            if (component1.status === Component.Ready) {
                              //  component1.createObject(null,  {replace: true, destroyOnPop: true, width: stackView.width, height: stackView.height, urlLink: model.url});
                           // stackView.pop()
                            stackView.push( "WebAppsPage.qml",
                                                  {urlLink: model.url, width: stackView.width, height: stackView.height})
//                            }
                        }
                    }
                }
            }
        }
    }
}



