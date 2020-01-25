import QtQuick 2.0

import "../../Components/OrderPages"
import "../../ComponentsCore/Views"
import "../../ComponentsCore/Shapes"
import "../../ApplicationCore/Style"

Item {
    id: root

    height: Interface.orderView.rowHeight
    width: crossOne.width + 20

    property color textColor: !currentItem ? Themes.selectedTheme.colors.appWhite : Themes.selectedTheme.colors.extremeBlack


    RoundedRectangle{
        id: crossOne

        width: packed.contentWidth + item.contentWidth + imageRectangle.width + 30
        height: Interface.orderView.rowHeight
        color: !currentItem ? Themes.selectedTheme.colors.primaryDark :
                              Themes.selectedTheme.colors.appWhite

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

                text: packedCount + "/" + ingredientCount
                color: textColor
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: Interface.fontSize.textSizeSmall
            }

            Text {
                id: item

                height: parent.height
                width: item.contentWidth

                text: model.itemName
                color: textColor
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: Interface.fontSize.textSizeSmall
            }

            Rectangle {
                id: imageRectangle

                height: parent.height
                width: parent.height * 0.8
                color: "transparent"

                Text {
                    id: user

                    height: parent.height * 0.75
                    width: parent.width * 0.75
                    text: Images.serving
                    verticalAlignment: Text.AlignVCenter
                    color: textColor
                    font.pixelSize: Interface.fontSize.textSizeSmall
                }
            }
        }
    }
}
