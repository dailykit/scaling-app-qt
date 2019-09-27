import QtQuick 2.9
import QtQuick.Window 2.2

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
    }

}
