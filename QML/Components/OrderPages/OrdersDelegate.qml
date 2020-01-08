import QtQuick 2.0
//import QtQuick.Controls.impl 2.3
import "../../ApplicationCore/Style"
import "../../ComponentsCore/Shapes"


RoundedRectangle {
    id: root

    color: Themes.selectedTheme.colors.primary
    radius: 5

    Rectangle{
        id: rect

        height: Interface.orderView.rowHeight * 0.8
        width: parent.width * 0.95
        color: Themes.selectedTheme.colors.primaryDark
        anchors.centerIn: parent

        Row {
            id: ingredientsRow

            anchors{
                left: parent.left
                leftMargin: parent.width * 0.03
            }

            height: Interface.orderView.rowHeight * 0.8
            width: parent.width * 0.8
            spacing: Interface.orderView.ingredientRowSpacing

            Text {
                id: totalIngredient

                text: packedCount + "/" + ingredientCount
                font.pixelSize: Interface.fontSize.textSizeSmall
                height: parent.height
                width: parent.width * 0.15
                color: Themes.selectedTheme.colors.appWhite
                fontSizeMode:  Text.Fit
                verticalAlignment: Text.AlignVCenter
            }

            Text {
                id: profile

                text: Images.serving
                font.pixelSize: Interface.fontSize.textSizeSmall
                height: parent.height
                width: parent.width * 0.15
                color: Themes.selectedTheme.colors.appWhite
                fontSizeMode:  Text.Fit
                verticalAlignment: Text.AlignVCenter
            }

            Text {
                id: servings

                text: itemServing
                font.pixelSize: Interface.fontSize.textSizeSmall
                height: parent.height
                width: parent.width * 0.15
                color: Themes.selectedTheme.colors.appWhite
                fontSizeMode:  Text.Fit
                verticalAlignment: Text.AlignVCenter
            }

            Text {
                id: item

                text: itemName
                font.pixelSize: Interface.fontSize.textSizeSmall
                height: parent.height
                width: parent.width * 0.5
                color: Themes.selectedTheme.colors.appWhite
                verticalAlignment: Text.AlignVCenter
            }


            Text {
                id: arrowIcon

                text: Images.rightArrow
                font.pixelSize: Interface.fontSize.textSizeSmall * 0.8
                height: parent.height
                width: parent.width * 0.15
                color: Themes.selectedTheme.colors.appWhite
                verticalAlignment: Text.AlignVCenter
                font.bold: true
            }
        }
    }
}
