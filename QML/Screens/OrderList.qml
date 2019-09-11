import QtQuick 2.0

import "../Components/OrderPages"
import "../ComponentsCore/Views"
import "../ApplicationCore/Style"

AppListView {
    id: trialRect


    model: orderView
    delegate: OrdersDelegate {
        id: delegateOrder

        height: Interface.orderView.rowHeight
        width: parent.width
    }
    snapMode: ListView.SnapToItem

    sectionProperty: "orderId"
    sectionDelegate: OrderSectionDelegate{
        id: delegateSection

        height: Interface.orderView.rowHeight
        width: parent.width
    }


}
