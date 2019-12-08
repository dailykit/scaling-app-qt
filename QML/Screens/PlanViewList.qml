import QtQuick 2.0
import QtQuick.Controls 2.5
import "../Components/OrderPages"
import "../ComponentsCore/Views"
import "../ComponentsCore/Shapes"
import "../ApplicationCore/Style"

Item{
    id: root

    AppListView {
        id: trialRect

        anchors.top: parent.top
        anchors.topMargin: parent.height * 0.02

        width: parent.width
        height: parent.height * 0.89

        model: planModel
        delegate: PlanningDelegate {
            id: delegateIngredient
            height: Interface.orderView.rowHeight + detailsList.height + 20
            width: parent.width

            MouseArea {
                anchors.fill: parent

                onClicked: {
                }
            }
        }
    }
}
