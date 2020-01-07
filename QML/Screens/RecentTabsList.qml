import QtQuick 2.0

import "../Components/OrderPages"
import "../ComponentsCore/Views"
import "../ComponentsCore/Shapes"
import "../ApplicationCore/Style"

Item{
    id: root
    width: parent.width
    height: parent.height
    property alias list: recentList

    AppListView {
        id: recentList

        width: parent.width
        height: parent.height
        orientation: Qt.Horizontal

        delegate: RecentTabsDelegate {
            id: recentDelegate
            height: Interface.orderView.rowHeight
            width: Interface.orderView.recentListWidth


            showOrder.onClicked: {
                itemsModel.setQuery(model.orderId)
                itemsModel.setCurrentItem(model.itemOrderId)

                weighingScale.orderId = model.itemOrderId
                ingredientModel.getIngredients(model.itemOrderId)

                loader.source = Qt.resolvedUrl("IngredientsPage.qml")
                recentTabs.setCurrentItem(model.itemOrderId)
            }

            closeTab.onClicked: {
                recentTabs.removeRecentItem(index)
            }
        }
    }
}
