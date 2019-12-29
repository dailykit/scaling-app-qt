import QtQuick 2.0
import QtQuick.Controls 2.5
import "../Components/OrderPages"
import "../"

import "../Components/OrderPages"
import "../ComponentsCore/Views"
import "../Screens"


Item {
    id: root
    height: parent.height
    width: parent.width

    property alias loader: orderLoader
    property alias weighScale: idWeightDetails


    Rectangle {
        id: idTopMargin
        height: 2
        width: parent.width
        color: "grey"
        anchors{

            top: parent.top
            topMargin: parent.width * 0.029
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
        }
    }

    Row{
        id: middleScreen


        width: parent.width * 0.9
        height: parent.height * 0.8
        spacing: parent.width * 0.03

        anchors{
            top: idTopMargin.bottom
            topMargin: parent.height * 0.02
            left: idleftMargin.right
            leftMargin: parent.width * 0.03
        }


        WeighingScale{
            id: idWeightDetails
            width: parent.width * 0.4
            height: parent.height * 0.4

        }

        Item {
            width: parent.width * 0.45
            height: parent.height
            BusyIndicator{
                id: busy
                anchors.centerIn: parent
            }

            Loader {
                id: orderLoader
                anchors.fill: parent
                active: true
                asynchronous: true
                visible: status == Loader.Ready
            }

            Connections{
                target: orderModel
                onModelReset:{
                    if(busy.running) {
                        busy.running = false
                        loader.source =  Qt.resolvedUrl( "../Screens/OrderList.qml")
                    }
                }
            }
        }
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
            stackView.push(Qt.createComponent(Qt.resolvedUrl("../Screens/Settings.qml")).createObject(parent, {width: stackView.width, height: stackView.height}))
        }

        options.planning.mouseArea.onClicked: {
            if(options.planning.state == "planning") {
                planModel.getIngredients()
                loader.source = Qt.resolvedUrl( "../Screens/PlanViewList.qml")
                options.planning.state = "real"
            } else if(options.planning.state == "real") {
              loader.source = Qt.resolvedUrl( "../Screens/OrderList.qml")
                options.planning.state = "planning"
            }
        }
    }

    Component.onCompleted: orderModel.setQuery()
}
