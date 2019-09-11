import QtQuick 2.0
import "../../ApplicationCore/Style"

Item {
    id: sectionDelegate1

    Rectangle{
        height: Interface.orderView.rowHeight * 0.8
        width: parent.width
        color: Themes.selectedTheme.colors.appWhite
        anchors.verticalCenter: parent.verticalCenter

        Row {
            id: ingredientsRow

            anchors{
                left: parent.left
                leftMargin: parent.width * 0.03
            }

            height: Interface.orderView.rowHeight * 0.8
            width: Interface.orderView.rowWidth * 0.8
            spacing: Interface.orderView.ingredientRowSpacing * 0.7

            Text {
                id: ingredientCount
                height: parent.height
                width: parent.width * 0.15
                verticalAlignment: Text.AlignVCenter
                text: "pa"
                color: Themes.selectedTheme.colors.extremeBlack
                font.pixelSize: Interface.fontSize.textSizeSmall
                fontSizeMode: Text.Fit
            }

            Text {
                id: order
                width: parent.width * 0.5
                height: parent.height
                verticalAlignment: Text.AlignVCenter
                text: section
                color: Themes.selectedTheme.colors.extremeBlack
                font.pixelSize: Interface.fontSize.textSizeSmall
                fontSizeMode:  Text.Fit
            }
        }
    }
}
