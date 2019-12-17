import QtQuick 2.0
import "../../ApplicationCore/Style"
import "../../ComponentsCore/Views"
import "../../Components/OrderPages"

Item {
    id: sectionDelegate1

    Column {
        width: parent.width
        height: parent.height
        spacing: 10 // TODO: remove the magic numbers


        Rectangle{
            id: title
            height: Interface.orderView.rowHeight
            width: parent.width
            color: Themes.selectedTheme.colors.primaryDark

            Row {
                id: ingredientsRow

                anchors{
                    left: parent.left
                    leftMargin: parent.width * 0.03
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
                    width: parent.width * 0.25
                    height: parent.height
                    verticalAlignment: Text.AlignVCenter
                    text: itemName
                    color: Themes.selectedTheme.colors.appWhite
                    font.pixelSize: Interface.fontSize.textSizeSmall * 0.8
                    wrapMode: Text.WordWrap
                }

                Text {
                    id: orderNumber
                    width: parent.width * 0.3
                    height: parent.height
                    verticalAlignment: Text.AlignVCenter
                    text: orderId
                    color: Themes.selectedTheme.colors.appWhite
                    font.pixelSize: Interface.fontSize.textSizeSmall * 0.8
                }

                Text {
                    id: weight
                    width: parent.width * 0.25
                    height: parent.height
                    verticalAlignment: Text.AlignVCenter
                    text: ingredientWeight + " " + "gm"
                    color: Themes.selectedTheme.colors.appWhite
                    font.pixelSize: Interface.fontSize.textSizeSmall * 0.8
                }
            }
        }
    }
}
