import QtQuick 2.0

import "../../Components/OrderPages"
import "../../ComponentsCore/Views"
import "../../ComponentsCore/Shapes"
import "../../ApplicationCore/Style"

Item {

    readonly property alias closeTab: closeTab
    readonly property alias showOrder: showOrder
    property string recentData

    property color textColor: currentItem ? Themes.selectedTheme.colors.extremeBlack : Themes.selectedTheme.colors.appWhite
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
            color: currentItem ? Themes.selectedTheme.colors.appWhite : Themes.selectedTheme.colors.primaryDark

            Text {
                id: crossOneText
                height: parent.height
                width: parent.width

                text: qsTr("x")
                color: textColor
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

            width: parent.width * 0.7
            height: Interface.orderView.rowHeight
            color: currentItem ? Themes.selectedTheme.colors.appWhite : Themes.selectedTheme.colors.primaryDark

            Text {
                id: recentText
                height: parent.height
                width: parent.width
                text: recentData
                elide: Text.ElideRight
                color: textColor
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: Interface.fontSize.textSizeSmall * 0.8
            }

            MouseArea{
                id: showOrder
                anchors.fill: parent
            }

        }

    }
}
