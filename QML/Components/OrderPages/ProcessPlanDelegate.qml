import QtQuick 2.0
import "../../ApplicationCore/Style"

Item {
    id: root

    height: Interface.orderView.rowHeight
    width: parent.width

    Rectangle {
        id: innerRect

        width: parent.width * 0.98
        anchors.centerIn: parent
        color: Themes.selectedTheme.colors.primaryDark
        height: Interface.orderView.rowHeight * 0.8

        Row {
            id: ingredientsRow

            anchors{
                left: parent.left
                leftMargin: parent.width * 0.08
            }

            height: parent.height
            width: parent.width
            spacing: 20

            Text {
                id: totalIngredients

                height: parent.height
                width: parent.width * 0.2
                text: ingredientPackedCount + " / " + ingredientProcessCount
                font.pixelSize: Interface.fontSize.textSizeSmall
                fontSizeMode: Text.Fit
                color: Themes.selectedTheme.colors.appWhite
                verticalAlignment: Text.AlignVCenter
            }

            Text {
                id: process

                height: parent.height
                width: parent.width * 0.4
                text: ingredientProcess
                color: Themes.selectedTheme.colors.appWhite
                font.pixelSize: Interface.fontSize.textSizeSmall
                fontSizeMode: Text.Fit
                verticalAlignment: Text.AlignVCenter
            }

            Text {
                id: weight

                height: parent.height
                width: parent.width * 0.15
                text: ingredientWeight + " gm"
                color: Themes.selectedTheme.colors.appWhite
                font.pixelSize: Interface.fontSize.textSizeSmall
                fontSizeMode: Text.Fit
                verticalAlignment: Text.AlignVCenter
            }

            Text {
                id: next

                height: parent.height
                width: parent.width * 0.15
                text: Images.rightArrow
                font.pixelSize: Interface.fontSize.textSizeSmall
                fontSizeMode: Text.Fit
                color: Themes.selectedTheme.colors.appWhite
                verticalAlignment: Text.AlignVCenter
                font.bold: true
            }
        }
    }
}
