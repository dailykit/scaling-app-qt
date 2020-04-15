import QtQuick 2.0
import "../../ApplicationCore/Style"


Rectangle {
    id: appsDelegate

    property color outerRectColor: "white"
    property string applicationText

    width: 250 //keeping constant so even though screen size increases this box will be stay constant
    height: 171
    color: outerRectColor


    Rectangle {
        id: iconRect

        anchors{
            top: parent.top
            topMargin: 10
            right: parent.right
            rightMargin: 20
        }

        width: 86
        height: 86
        color: Themes.selectedTheme.colors.appWhite
        opacity: 0.4
    }

    Rectangle {
        id: appNameText

        anchors{
            left: parent.left
            leftMargin: Interface.landingPages.outerRectWidth * 0.092
            bottom: parent.bottom
            bottomMargin: Interface.landingPages.outerRectWidth * 0.052
        }
        width: Interface.landingPages.appNameTextWidth
        height: Interface.landingPages.appNameTextHeight
        color: "transparent"

        Text {
            id: appName
            anchors.fill: parent
            text: applicationText
            color: Themes.selectedTheme.colors.appWhite
            font.pixelSize: 16
        }

    }


}
