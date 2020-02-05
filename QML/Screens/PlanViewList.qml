import QtQuick 2.0
import QtQuick.Controls 2.5
import "../Components/OrderPages"
import "../ComponentsCore/Views"
import "../ComponentsCore/Shapes"
import "../ApplicationCore/Style"

Item{
    id: root

    RecentTabsPlanViewList {
        id: recentList

        anchors.top: parent.top
        width: parent.width * 0.8
        height: Interface.orderView.rowHeight
    }

    AppListView {
        id: listView

        anchors.top: recentList.bottom
        anchors.topMargin: parent.height * 0.02

        width: parent.width
        height: parent.height * 0.89

        model: planModel
        delegate: PlanningDelegate {
            id: delegateIngredient
            height: Interface.orderView.rowHeight + detailsList.height
            width: parent.width

        }
    }
}
