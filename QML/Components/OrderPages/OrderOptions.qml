import QtQuick 2.0
import "../../ApplicationCore/Style"
import "../../ComponentsCore/Shapes"
import "../../ComponentsCore/Views"

Item {
    id: root

    property color textColor
    property alias collapse: collapse

    property alias deleteIngredient: deleteIngredient
    property alias repack: repack
    property alias reprint: reprint

    Row {

        width: parent.width
        height: parent.height
        spacing: parent.width * 0.025

        RoundedRectangle {
            id: closeOptions

            width: parent.width * 0.23
            height: parent.height * 0.5
            color: "transparent"

            Text {
                id: closeOptionsText

                width: parent.width
                height: parent.height
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                text: Images.rightArrow
                color: textColor
                font.pixelSize: Interface.fontSize.textSizeSmall * 0.9
                font.family: Images.iconfont.name
            }
            MouseArea {
                id: collapse
                anchors.fill: parent
            }
        }

        RoundedRectangle {
            id: deleteIngredientRect

            width: parent.width * 0.11
            height: parent.height * 0.55
            color: Themes.selectedTheme.colors.primary

            Text {
                id: deleteIngredientText

                width: parent.width
                height: parent.height
                anchors.centerIn: parent
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                text: Images.close
                color: Themes.selectedTheme.colors.appWhite
                font.pixelSize: Interface.fontSize.textSizeSmall * 0.9
                font.family: Images.iconfont.name
            }

            MouseArea {
                id: deleteIngredient
                anchors.fill: parent
            }
        }

        RoundedRectangle {
            id: repackRect

            width: parent.width * 0.11
            height: parent.height * 0.55
            color: Themes.selectedTheme.colors.primary

            Text {
                id: repackText

                width: parent.width
                height: parent.height
                anchors.centerIn: parent
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                text: Images.repack
                color: Themes.selectedTheme.colors.appWhite
                font.pixelSize: Interface.fontSize.textSizeSmall * 0.9
                font.family: Images.iconfont.name
            }

            MouseArea{
                id: repack
                anchors.fill: parent
            }
        }

        RoundedRectangle {
            id: reprintRect

            width: parent.width * 0.11
            height: parent.height * 0.55
            color: Themes.selectedTheme.colors.primary

            Text {
                id: reprintText

                width: parent.width
                height: parent.height
                anchors.centerIn: parent
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                text: Images.label
                color: Themes.selectedTheme.colors.appWhite
                font.pixelSize: Interface.fontSize.textSizeSmall * 0.9
                font.family: Images.iconfont.name
            }

            MouseArea {
               id: reprint
               anchors.fill: parent
            }
        }
    }
}
