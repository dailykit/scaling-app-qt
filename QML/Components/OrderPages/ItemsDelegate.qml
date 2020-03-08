import QtQuick 2.0

import "../../Components/OrderPages"
import "../../ComponentsCore/Views"
import "../../ComponentsCore/Shapes"
import "../../ApplicationCore/Style"

Item {
    id: root

    height: Interface.orderView.rowHeight
    width: crossOne.width + 20

    property color textColor: (currentItem || delegateIngredient.ListView.isCurrentItem) ? Themes.selectedTheme.colors.extremeBlack : Themes.selectedTheme.colors.appWhite
    property alias packed: packed
    property alias item: item

    RoundedRectangle{
        id: crossOne

        width: packed.contentWidth + item.contentWidth + user.width
        height: Interface.orderView.rowHeight
        color: (currentItem || delegateIngredient.ListView.isCurrentItem) ? Themes.selectedTheme.colors.appWhite :
                                                                             Themes.selectedTheme.colors.primaryDark

        Row {

            height: parent.height
            width: parent.width
            spacing: Interface.options.spacing

            anchors.left: parent.left
            anchors.leftMargin: Interface.options.spacing

            Text {
                id: packed

                height: parent.height
                width: packed.contentWidth


                color: textColor
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: Interface.fontSize.textSizeSmall
            }

            Text {
                id: item

                height: parent.height
                width: item.contentWidth

           //     text:
                color: textColor
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: Interface.fontSize.textSizeSmall
            }

            Text {
                id: user

                height: parent.height
                width: Interface.options.iconSize + 30
                text: Images.serving
                verticalAlignment: Text.AlignVCenter
                color: textColor
                font.pixelSize: Interface.fontSize.textSizeSmall

            }
        }
    }
    Component.onCompleted: console.log("current",delegateIngredient.ListView.isCurrentItem )
}
