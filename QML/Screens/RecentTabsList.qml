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

        model: recentTabs
        delegate: RecentTabsDelegate {
            id: recentDelegate
            height: Interface.orderView.rowHeight
            width: Interface.orderView.recentListWidth


            showOrder.onClicked: {
                ingredientModel.getIngredients(model.itemOrderId)
                weighingScale.orderId = model.itemOrderId
                loader.source = Qt.resolvedUrl("IngredientsPage.qml")
            }

            closeTab.onClicked: {
                recentTabs.removeRecentItem(index)
            }
        }
    }
}
