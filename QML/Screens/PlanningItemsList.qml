import QtQuick 2.0

import "../Components/OrderPages"
import "../ComponentsCore/Views"
import "../ComponentsCore/Shapes"
import "../ApplicationCore/Style"

Item{
    id: root
    width: parent.width
    height: parent.height

    property alias recentList: planItemsList
    property string ingredientName

    AppListView {
        id: planItemsList

        width: parent.width
        height: parent.height
        orientation: Qt.Horizontal
        snapMode: ListView.SnapToItem

        currentIndex: itemIndex
        delegate: ItemsDelegate {
            id: delegateIngredient
            height: Interface.orderView.rowHeight

            item.text: ingredientProcess
            packed.text: ingredientPackedCount + "/" + ingredientProcessCount

            MouseArea {
                anchors.fill: parent
                enabled: !planItemsList.isCurrentItem
                onClicked: {
                    planItemsList.currentIndex = index
                    console.log("curenttnnt", planItemsList.currentIndex)
                    mainModel.planViewItemModel.getItems(ingredientProcess, mainModel.planViewItemModel.ingredientName, mainModel.planViewItemModel.totalWeight)
                   // itemModel.currentItem = ingredientProcess
                    mainModel.recentIngredients.addRecentItem(mainModel.planViewItemModel.ingredientName, ingredientProcess, mainModel.planViewItemModel.totalWeight)
                }
            }
        }

        Component.onCompleted: {
            console.log("index", itemIndex, currentIndex)

        }
    }
}
