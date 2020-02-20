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
        model: mainModel.recentTabs

        delegate: RecentTabsDelegate {
            id: recentDelegate
            height: Interface.orderView.rowHeight
            width: Interface.orderView.recentListWidth
            recentData: model.orderNumber


            showOrder.onClicked: {
                mainModel.itemsModel.setQuery(model.orderId)
                mainModel.itemsModel.setCurrentItem(model.itemOrderId)

                mainModel.weighingScale.orderId = model.itemOrderId
                mainModel.ingredientsModel.getIngredients(model.itemOrderId)

                loader.source = Qt.resolvedUrl("IngredientsPage.qml")
                mainModel.recentTabs.setCurrentItem(model.itemOrderId)
            }

            closeTab.onClicked: {
                mainModel.recentTabs.removeRecentItem(index)
            }
        }
    }
}
