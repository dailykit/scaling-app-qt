import QtQuick 2.0
import QtQuick.Controls 2.5
import "../Components/OrderPages"
import "../ComponentsCore/Views"
import "../ComponentsCore/Shapes"
import "../ApplicationCore/Style"

Item{
    id: root
    property bool isListLoaded: false

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

            list.model: mainModel.recentTabs
        }
    }

    Item {

        width: parent.width
        height: parent.height * 0.89

        anchors.top: allOrders.bottom
        anchors.topMargin: parent.height * 0.02

        AppListView {
            id: orderList
            anchors.fill: parent

            model: mainModel.ordersViewModel

            delegate: OrdersDelegate
            {
                id: delegateOrder

                height: Interface.orderView.rowHeight
                width: parent.width

                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        mainModel.ingredientsModel.getIngredients(model.itemOrderId)
                        mainModel.weighingScale.orderId = model.orderId
                        mainModel.weighingScale.itemName = model.itemName
                        loader.setSource(Qt.resolvedUrl("IngredientsPage.qml"))
                        mainModel.recentTabs.addRecentItem(model.orderNumber, model.itemOrderId, model.orderId)
                        mainModel.itemsModel.setCurrentItem(model.itemOrderId)
                        mainModel.itemsModel.setQuery(model.orderId)
                        mainModel.ingredientsModel.itemName = model.itemName
                        mainModel.ingredientsModel.orderNumber = model.orderNumber
                        mouse.accepted  = true
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
}
