import QtQuick 2.0
import "../../ApplicationCore/Style"

Rectangle {
    id: root

    width: parent.width
    color: Themes.selectedTheme.colors.extremeBlack
    height: 10
    enabled: !ingredientIsPacked


    Row {
        id: ingredientsRow

        anchors{
            left: parent.left
            leftMargin: parent.width * 0.15
        }

        height: parent.height
        width: parent.width * 0.8
        spacing: 20

        Text {
            id: process
            text: ingredientProcess + " - " + ingredientName
            font.pixelSize: Interface.fontSize.textSizeSmall * 0.7
            height: parent.height
            width: parent.width * 0.8
            color: !ingredientIsPacked ? Themes.selectedTheme.colors.appWhite : "grey"
            verticalAlignment: Text.AlignVCenter
            font.bold: true
        }

        Text {
            id: weight
            text: quantity + " " +ingredientWeight
            font.pixelSize: Interface.fontSize.textSizeSmall * 0.7
            height: parent.height * 0.7
            width: parent.width * 0.15
            color: !ingredientIsPacked ? Themes.selectedTheme.colors.appWhite : "grey"
            fontSizeMode:  Text.Fit
            verticalAlignment: Text.AlignVCenter
            font.bold: true
        }
    }

}


