import QtQuick 2.0
import "../../ApplicationCore/Style"


Rectangle {
    id: root
    color: Themes.selectedTheme.colors.extremeBlack


    Row {
        id: ingredientsRow

        anchors{
            left: parent.left
            leftMargin: parent.width * 0.15
        }

        height: Interface.orderView.rowHeight * 0.8
        width: parent.width * 0.8
        spacing: 20

        Text {
            id: process
            text: ingredientProcess + " - " + ingredientName
            font.pixelSize: Interface.fontSize.textSizeSmall * 0.7
            height: parent.height
            width: parent.width * 0.8
            color: Themes.selectedTheme.colors.appWhite
           // fontSizeMode:  Text.Fit
            verticalAlignment: Text.AlignVCenter
            font.bold: true

        }

        Text {
            id: weight
            text: quantity + " " +ingredientWeight
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


