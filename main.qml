import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.5

import "QML/ApplicationCore/Style"
import "QML/Components/OrderPages"
import "QML/ComponentsCore/Views"
import "QML/MainPages"
import "QML/Screens"

Window {
    visible: true
    color: "black"

    width: Screen.width
    height: Screen.height


    Rectangle {
        id: idTopMargin
        height: 2
        width: parent.width
        color: "grey"
        anchors{

            top: parent.top
            topMargin: 40
        }
    }

    Rectangle {
        id: idleftMargin
        height: parent.height
        width: 2
        color: "grey"
        anchors{
            left: parent.left
            leftMargin: parent.width * 0.055
            top: idTopMargin.bottom
            //topMargin: parent.height * 0.05
        }
    }

    //    WeighingScale{
    //        id: idWeightDetails
    //        height: parent.height * 0.4
    //        width: parent.width * 0.4

    //        anchors{
    //            top: parent.top
    //            topMargin: parent.height * 0.09
    //            left: idleftMargin.right
    //            leftMargin: parent.width * 0.03
    //        }

    //    }

    //    OrderList {
    //        id: orderList
    //        width: parent.width * 0.4
    //        height: parent.height * 0.72

    //        anchors {
    //            top: parent.top
    //            topMargin: parent.height * 0.09
    //            left: idWeightDetails.right
    //            leftMargin: parent.width * 0.03
    //        }
    //    }

    MainOrdersPage {
        id: mainOrders

        width: parent.width * 0.9
        height: parent.height * 0.8
        spacing: parent.width * 0.03

        anchors{
            top: parent.top
            topMargin: parent.height * 0.08
            left: idleftMargin.right
            leftMargin: parent.width * 0.03
        }


        loader.source:  Qt.resolvedUrl( "QML/Screens/OrderList.qml")


    }



    RightBar {
        id: idRightMargin
        height: parent.height
        width:  parent.width * 0.04
        anchors{
            right: parent.right
            rightMargin: parent.width * 0.055
            top: idTopMargin.bottom
        }
        options.settings.mouseArea.onClicked :{
           stackView.push(Qt.createComponent("QML/Screens/Settings.qml").createObject())
        }
    }


    StackView {
        id: stackView
        property real offset: 10
        width: 100; height: 100

        initialItem: Component {
            id: page
            Rectangle {
                property real pos: StackView.index * stackView.offset
                property real hue: Math.random()
                color: Qt.hsla(hue, 0.5, 0.8, 0.6)
                border.color: Qt.hsla(hue, 0.5, 0.5, 0.9)
                StackView.visible: true
            }
        }

        pushEnter: Transition {
            id: pushEnter
            ParallelAnimation {
                PropertyAction { property: "x"; value: pushEnter.ViewTransition.item.pos }
                NumberAnimation { properties: "y"; from: pushEnter.ViewTransition.item.pos + stackView.offset; to: pushEnter.ViewTransition.item.pos; duration: 400; easing.type: Easing.OutCubic }
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

}
