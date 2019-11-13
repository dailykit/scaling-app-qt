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

        RecentTabsList {
            id: recentList

            width: parent.width * 0.8
            height: Interface.orderView.rowHeight
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
                    recentTabs.addRecentItem(model.orderNumber, model.itemOrderId)
                    itemsModel.setQuery(model.orderId)
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
