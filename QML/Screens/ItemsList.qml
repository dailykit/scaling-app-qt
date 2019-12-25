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
        snapMode: ListView.SnapToItem

        model: itemsModel
        delegate: ItemsDelegate {
            id: delegateIngredient
            height: Interface.orderView.rowHeight

            MouseArea {
                anchors.fill: parent
                enabled: !currentItem
                onClicked: {
                    ingredientModel.getIngredients(model.itemOrderId)
                    weighingScale.orderId = model.itemOrderId
                    weighingScale.itemName = model.itemName
                    itemsModel.setCurrentItem(model.itemOrderId)
                }
            }
        }
    }
}
