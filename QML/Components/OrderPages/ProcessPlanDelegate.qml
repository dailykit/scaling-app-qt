import QtQuick 2.0
import "../../ApplicationCore/Style"

Rectangle {
    id: root
    color: Themes.selectedTheme.colors.extremeBlack
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
                text: ingredientPackedCount + " / " + ingredientProcessCount
                font.pixelSize: Interface.fontSize.textSizeSmall * 0.7
                height: parent.height
                width: parent.width * 0.2
                color: Themes.selectedTheme.colors.appWhite
                verticalAlignment: Text.AlignVCenter
                font.bold: true
            }

            Text {
                id: process
                text: ingredientProcess
                font.pixelSize: Interface.fontSize.textSizeSmall * 0.7
                height: parent.height
                width: parent.width * 0.4
                color: Themes.selectedTheme.colors.appWhite
                verticalAlignment: Text.AlignVCenter
                font.bold: true
            }

            Text {
                id: weight
                text: ingredientWeight + " gm"
                font.pixelSize: Interface.fontSize.textSizeSmall * 0.7
                height: parent.height * 0.7
                width: parent.width * 0.15
                color: Themes.selectedTheme.colors.appWhite
                fontSizeMode:  Text.Fit
                verticalAlignment: Text.AlignVCenter
                font.bold: true
            }
        }
    }
}
