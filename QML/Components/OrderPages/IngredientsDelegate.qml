import QtQuick 2.0
import "../../ApplicationCore/Style"

Rectangle {
    id: root


    width: parent.width
    color: delegateIngredientInternal.ListView.isCurrentItem ? Themes.selectedTheme.colors.appWhite : ingredientIsPacked ? Themes.selectedTheme.colors.primary :
                                                                                                                           Themes.selectedTheme.colors.appBlack
    height: 10
    enabled: !ingredientIsPacked

    property color textColor: delegateIngredientInternal.ListView.isCurrentItem ? Themes.selectedTheme.colors.extremeBlack : Themes.selectedTheme.colors.appWhite

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
            color: textColor
            verticalAlignment: Text.AlignVCenter
            font.bold: true
        }

        Text {
            id: weight
            text: quantity + " " +ingredientWeight
            font.pixelSize: Interface.fontSize.textSizeSmall * 0.7
            height: parent.height * 0.7
            width: parent.width * 0.15
            color: textColor
            fontSizeMode:  Text.Fit
            verticalAlignment: Text.AlignVCenter
            font.bold: true
        }
    }

}


