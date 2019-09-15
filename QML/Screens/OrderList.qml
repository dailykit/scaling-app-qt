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
                console.log("order", model.itemOrderId)
                ingredientModel.getIngredients(model.itemOrderId)
                loader.source = Qt.resolvedUrl( "IngredientsPage.qml")
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
