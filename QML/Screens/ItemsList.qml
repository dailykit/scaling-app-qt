import QtQuick 2.0

import "../Components/OrderPages"
import "../ComponentsCore/Views"
import "../ComponentsCore/Shapes"
import "../ApplicationCore/Style"

Item{
    id: root
    width: parent.width
    height: parent.height

    property alias recentList: recentList

    AppListView {
        id: recentList

        width: parent.width
        height: parent.height
        orientation: Qt.Horizontal
        snapMode: ListView.SnapToItem

        model: mainModel.itemsModel
        delegate: ItemsDelegate {
            id: delegateIngredient
            height: Interface.orderView.rowHeight

            item.text: model.itemName
            packed.text: packedCount + "/" + ingredientCount

            MouseArea {
                anchors.fill: parent
                enabled: !currentItem
                onClicked: {
                    mainModel.ingredientsModel.getIngredients(model.itemOrderId)
                    mainModel.weighingScale.orderId = model.itemOrderId
                    mainModel.weighingScale.itemName = model.itemName
                    mainModel.itemsModel.setCurrentItem(model.itemOrderId)
                }
            }
        }
    }
}
