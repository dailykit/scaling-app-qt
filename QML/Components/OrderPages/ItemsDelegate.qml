import QtQuick 2.0

import "../../Components/OrderPages"
import "../../ComponentsCore/Views"
import "../../ComponentsCore/Shapes"
import "../../ApplicationCore/Style"

Item {
     id: root

    RoundedRectangle{
        id: crossOne

        width: packed.contentWidth + item.contentWidth + imageRectangle.width + 30
        height: Interface.orderView.rowHeight
        color: Themes.selectedTheme.colors.primaryDark

        Column {

            height: parent.height
            width: parent.width
            spacing: Interface.options.spacing

            Text {
                id: packed
                height: parent.height
                width: 20

                text: packedCount + "/" + ingredientCount
                color: Themes.selectedTheme.colors.appWhite
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: Interface.fontSize.textSizeSmall
            }

            Text {
                id: item
                height: parent.height
                width: 100

                text: itemName
                color: Themes.selectedTheme.colors.appWhite
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: Interface.fontSize.textSizeSmall
                visible: !currentItem
            }

            Rectangle {
                id: imageRectangle

                height: parent.height
                width: 30
                color: "transparent"

                Image {
                    id: user

                    height: parent.height * 0.8
                    width: parent.width * 0.4
                    source: Images.orderImage //TODO: change the image to person after getting the correct one
                    anchors.centerIn: parent
                }
                visible: !currentItem
            }
        }

        Component.onCompleted: {
            console.log("itemsssss")
        }
    }
}
