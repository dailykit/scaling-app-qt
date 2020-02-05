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
        id: recentIngredientList

        width: parent.width
        height: parent.height
        orientation: Qt.Horizontal
        model: mainModel.recentIngredients

        delegate: RecentTabsDelegate {
            id: recentDelegate
            height: Interface.orderView.rowHeight
            width: Interface.orderView.recentListWidth

            recentData: model.recentIngredient


            showOrder.onClicked: {
                console.log("ingredient process", ingredientProcess)
                planningItems.getItems(ingredientProcess, recentIngredient, totalWeight)
                loader.source = Qt.resolvedUrl("PlanViewItemList.qml")
            }

            closeTab.onClicked: {
                mainModel.recentIngredients.removeRecentItem(index)
            }
        }
    }
}
