import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 2.2

import "QML/ApplicationCore/Style"
import "QML/Components/OrderPages"
import "QML/ComponentsCore/Views"
import "QML/MainPages"
import "QML/Screens"
import "QML/MainPages"

Window {
    visible: true
    color: "black"

    width: Screen.width
    height: Screen.height

    property alias stackView: stackView



    StackView {
        id: stackView
        property real offset: 10
        width: parent.width
        height: parent.height

        initialItem: Qt.createComponent(Qt.resolvedUrl("QML/MainPages/LoginPage.qml")).createObject()

        pushEnter: Transition {
            id: pushEnter
            ParallelAnimation {
                PropertyAction { property: "x"; value: pushEnter.ViewTransition.item.pos }
                NumberAnimation { properties: "y"; from: pushEnter.ViewTransition.item.pos + stackView.offset; duration: 400; easing.type: Easing.OutCubic }
                NumberAnimation { property: "opacity"; from: 0; to: 1; duration: 400; easing.type: Easing.OutCubic }
            }
        }
        popExit: Transition {
            id: popExit
            ParallelAnimation {
                PropertyAction { property: "x"; value: popExit.ViewTransition.item.pos }
                NumberAnimation { properties: "y"; from: popExit.ViewTransition.item.pos; to: popExit.ViewTransition.item.pos + stackView.offset; duration: 400; easing.type: Easing.OutCubic }
                NumberAnimation { property: "opacity"; from: 1; to: 0; duration: 400; easing.type: Easing.OutCubic }
            }
        }

        pushExit: Transition {
            id: pushExit
            PropertyAction { property: "x"; value: pushExit.ViewTransition.item.pos }
            PropertyAction { property: "y"; value: pushExit.ViewTransition.item.pos }
        }
        popEnter: Transition {
            id: popEnter
            PropertyAction { property: "x"; value: popEnter.ViewTransition.item.pos }
            PropertyAction { property: "y"; value: popEnter.ViewTransition.item.pos }
        }
    }


    Item {
        Connections {
            target: loginAccess

            onLoggedOut: {
                //keeping this code for now as commented
//                var component = Qt.createComponent(Qt.resolvedUrl("QML/MainPages/LoginPage.qml"))
//                if (component.status === Component.Ready) {
//                    component.createObject(null, {width: stackView.width, height: stackView.height});
//                    stackView.push(component, {replace: true, destroyOnPop: true})
//                    console.log("depppppppppppppppp", stackView.depth)

            //}
                stackView.pop()
            }
        }
    }

}
