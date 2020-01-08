import QtQuick 2.0
import "../ApplicationCore/Style"
Item {

    Row {
        id: topBar

        spacing: 10

        Rectangle {
            id: logoRect

            width: Interface.logo.iconSize
            height: Interface.logo.iconSize

            Image {
                id: logoImage

                anchors.fill: parent
                source: Images.logo
            }
        }

        Text {
            id: appName

            width: parent.width * 0.2
            height: parent.height * 0.8

            verticalAlignment: Text.AlignHCenter
            text: qsTr("DAILYKIT")
            color: Themes.selectedTheme.colors.appWhite
            font.pixelSize: Interface.fontSize.textSizeSmall
        }

        Rectangle {
            id: blank

            width: parent.width * 0.68
            height: parent.height
            color: "transparent"
        }


        Text {
            id: menu

            width: Interface.options.iconSize
            height: Interface.options.iconSize

            verticalAlignment: Text.AlignHCenter
            text: Images.menu
            color: Themes.selectedTheme.colors.appWhite
            font.pixelSize: Interface.fontSize.textSizeSmall
            font.bold: true
        }

        Text {
            id: userIcon

            width: Interface.options.iconSize
            height: Interface.options.iconSize

            verticalAlignment: Text.AlignHCenter
            text: Images.serving
            color: Themes.selectedTheme.colors.appWhite
            font.pixelSize: Interface.fontSize.textSizeSmall
            font.bold: true
        }

        Text {
            id: userName

            width: Interface.options.iconSize
            height: Interface.options.iconSize

            verticalAlignment: Text.AlignHCenter
            text: qsTr("John")
            color: Themes.selectedTheme.colors.appWhite
            font.pixelSize: Interface.fontSize.textSizeSmall
            font.bold: true
        }
    }
}

