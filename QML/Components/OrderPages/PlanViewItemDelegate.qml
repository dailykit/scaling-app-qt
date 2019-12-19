import QtQuick 2.0
import "../../ApplicationCore/Style"
import "../../ComponentsCore/Views"
import "../../Components/OrderPages"

Item {
    id: sectionDelegate1

    Column {
        width: parent.width * 0.98
        height: parent.height
        spacing: 10 // TODO: remove the magic numbers
        anchors.centerIn: parent


        Rectangle{
            id: title
            height: Interface.orderView.rowHeight * 1.2
            width: parent.width
            color: Themes.selectedTheme.colors.primary

            Row {
                id: ingredientsRow

                anchors{
                    left: parent.left
                    leftMargin: parent.width * 0.02
                }

                height: Interface.orderView.rowHeight
                width: Interface.orderView.rowWidth
                spacing: Interface.orderView.ingredientRowSpacing * 0.7

                Text {
                    id: ingredientCount
                    height: parent.height
                    text: index + 1 + ")"
                    width: parent.width * 0.03
                    verticalAlignment: Text.AlignVCenter
                    color: Themes.selectedTheme.colors.appWhite
                    font.pixelSize: Interface.fontSize.textSizeSmall
                    fontSizeMode: Text.Fit
                }

                Text {
                    id: item
                    width: parent.width * 0.32
                    height: parent.height
                    verticalAlignment: Text.AlignVCenter
                    text: itemName
                    color: Themes.selectedTheme.colors.appWhite
                    font.pixelSize: Interface.fontSize.textSizeSmall * 0.98
                    elide: Text.ElideRight
                }

                Text {
                    id: orderNo
                    width: parent.width * 0.33
                    height: parent.height
                    verticalAlignment: Text.AlignVCenter
                    text: orderId
                    color: Themes.selectedTheme.colors.appWhite
                    font.pixelSize: Interface.fontSize.textSizeSmall * 0.98
                    elide: Text.ElideRight
                }

                Text {
                    id: weight
                    width: parent.width * 0.12
                    height: parent.height
                    verticalAlignment: Text.AlignVCenter
                    text: ingredientWeight + " " + "gm"
                    color: Themes.selectedTheme.colors.appWhite
                    font.pixelSize: Interface.fontSize.textSizeSmall * 0.98
                }

                Text {
                    id: back
                    width: parent.width * 0.15
                    height: parent.height
                    verticalAlignment: Text.AlignVCenter
                    text: backIcon
                    color: Themes.selectedTheme.colors.appWhite
                    font.pixelSize: Interface.fontSize.textSizeSmall * 0.98
                }
            }
        }
    }
}
