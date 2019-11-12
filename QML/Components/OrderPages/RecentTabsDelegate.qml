import QtQuick 2.0

import "../../Components/OrderPages"
import "../../ComponentsCore/Views"
import "../../ComponentsCore/Shapes"
import "../../ApplicationCore/Style"

Item {

    readonly property alias closeTab: closeTab
    readonly property alias showOrder: showOrder
    Row {
        id: allOrders
        anchors.top: parent.top

        height: Interface.orderView.rowHeight
        width: parent.width
        spacing: Interface.options.spacing

        RoundedRectangle{
            id: crossOne

            width: parent.width * 0.2
            height: Interface.orderView.rowHeight
            color: Themes.selectedTheme.colors.primaryDark

            Text {
                id: crossOneText
                height: parent.height
                width: parent.width

                text: qsTr("x")
                color: Themes.selectedTheme.colors.appWhite
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: Interface.fontSize.textSizeSmall
            }
            MouseArea{
                id: closeTab
                anchors.fill: parent
            }

        }


        RoundedRectangle{
            id: orderIdBack

            width: parent.width * 0.5
            height: Interface.orderView.rowHeight
            color: Themes.selectedTheme.colors.primaryDark

            Text {
                id: orderIdText
                height: parent.height
                width: parent.width
                text: model.orderId
                elide: Text.ElideLeft
                color: Themes.selectedTheme.colors.appWhite
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: Interface.fontSize.textSizeSmall
            }

            MouseArea{
                id: showOrder
                anchors.fill: parent
            }

        }

    }
}