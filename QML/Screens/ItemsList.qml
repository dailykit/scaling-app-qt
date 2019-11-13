import QtQuick 2.0

import "../Components/OrderPages"
import "../ComponentsCore/Views"
import "../ComponentsCore/Shapes"
import "../ApplicationCore/Style"

Item{
    id: root
    width: parent.width
    height: parent.height

    AppListView {
        id: recentList

        width: parent.width
        height: parent.height
        orientation: Qt.Horizontal

        model: itemsModel
        delegate: ItemsDelegate {
            id: delegateIngredient
            height: Interface.orderView.rowHeight
            width: Interface.orderView.recentListWidth


            MouseArea {
                anchors.fill: parent
                onClicked: {
                    ingredientModel.getIngredients(model.itemOrderId)
                    weighingScale.orderId = model.itemOrderId
                }
            }

            Component.onCompleted: console.log("loading")
        }
    }

    Component.onCompleted: console.log("items list loaded")
}
