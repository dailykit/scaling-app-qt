import QtQuick 2.0

import "../Components/OrderPages"
import "../ComponentsCore/Views"
import "../ApplicationCore/Style"

AppListView {
    id: trialRect


    model: orderModel
    delegate: OrdersDelegate {
        id: delegateOrder

        height: Interface.orderView.rowHeight
        width: parent.width

        MouseArea{
            anchors.fill: parent
            onClicked: {
                ingredientModel.getIngredients(model.itemOrderId)
                loader.source = Qt.resolvedUrl("IngredientsPage.qml")
                loader.item.orderNumber = model.orderNumber
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
