import QtQuick 2.0

import "../Components/OrderPages"
import "../ComponentsCore/Views"
import "../ComponentsCore/Shapes"
import "../ApplicationCore/Style"

Item{
    id: root

    Row {
        id: allOrders
        anchors.top: parent.top

        height: Interface.orderView.rowHeight
        width: parent.width
        spacing: 10

        RoundedRectangle{
            id: orderId

            width: parent.width * 0.2
            height: Interface.orderView.rowHeight
            color: Themes.selectedTheme.colors.appWhite

            Text {
                id: allOrderText
                height: parent.height
                width: parent.width
                text: qsTr("All Orders")
                color: Themes.selectedTheme.colors.extremeBlack
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: Interface.fontSize.textSizeSmall
            }

        }

        RoundedRectangle{
            id: crossOne

            width: parent.width * 0.1
            height: Interface.orderView.rowHeight
            color: Themes.selectedTheme.colors.primaryDark

            Text {
                id: crossOneText
                height: parent.height
                width: parent.width

                text: qsTr("x")
                color: Themes.selectedTheme.colors.appWhite
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: Interface.fontSize.textSizeSmall
            }
            MouseArea{
                id: clickArea
                anchors.fill: parent
            }

        }


        RoundedRectangle{
            id: orderIdBack

            width: parent.width * 0.1
            height: Interface.orderView.rowHeight
            color: Themes.selectedTheme.colors.primaryDark

            Text {
                id: orderIdText
                height: parent.height
                width: parent.width

                text: qsTr("3")
                color: Themes.selectedTheme.colors.appWhite
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: Interface.fontSize.textSizeSmall
            }

        }

        RoundedRectangle{
            id: crossTwo

            width: parent.width * 0.1
            height: Interface.orderView.rowHeight
            color: Themes.selectedTheme.colors.primaryDark

            Text {
                id: crossTwoText
                height: parent.height
                width: parent.width

                text: qsTr("x")
                color: Themes.selectedTheme.colors.appWhite
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: Interface.fontSize.textSizeSmall
            }
            MouseArea{
                id: clickAreaTwo
                anchors.fill: parent
            }

        }


        RoundedRectangle{
            id: orderNumberBack

            width: parent.width * 0.1
            height: Interface.orderView.rowHeight
            color: Themes.selectedTheme.colors.primaryDark

            Text {
                id: orderNumberText
                height: parent.height
                width: parent.width

                text: qsTr("27")
                color: Themes.selectedTheme.colors.appWhite
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: Interface.fontSize.textSizeSmall
            }

        }
    }

    AppListView {
        id: trialRect

        width: parent.width
        height: parent.height * 0.89

        anchors.top: allOrders.bottom
        anchors.topMargin: parent.height * 0.02

        model: orderModel
        delegate: OrdersDelegate {
            id: delegateOrder

            height: Interface.orderView.rowHeight
            width: parent.width

            MouseArea{
                anchors.fill: parent
                onClicked: {
                    ingredientModel.getIngredients(model.itemOrderId)
                    weighingScale.orderId = model.orderId
                    loader.source = Qt.resolvedUrl("IngredientsPage.qml")
                    loader.item.orderNumber = model.orderNumber
                    loader.item.itemName = model.itemName

                }
            }
        }
        snapMode: ListView.SnapToItem

        sectionProperty: "orderId"
        sectionDelegate: OrderSectionDelegate{
            id: delegateSection

            height: Interface.orderView.rowHeight
            width: parent.width
        }


    }
}
