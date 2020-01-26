import QtQuick 2.0
import QtQuick.Controls 2.4
import "../../ApplicationCore/Style"

Dialog {
    id: dialog


    property string labelText
    property string titleText
    property alias yesButton: yesMouseArea
    property alias noButton: noMouseArea

    modal: true
    anchors.centerIn: Overlay.overlay
    background: Rectangle {
        implicitWidth: Interface.options.dialogWidth
        implicitHeight: dialog.height
        color: Themes.selectedTheme.colors.primaryDark
    }

    contentItem : Column {
        spacing: Interface.options.spacing
        Text {
            id: titleT
            text: titleText
            width: Interface.options.columnWidth
            height: Interface.options.columnWidth
            color: Themes.selectedTheme.colors.appWhite
            font.pixelSize: Interface.fontSize.textSizeSmall
        }

        Label {
            text: labelText
            font.pixelSize: Interface.fontSize.textSizeSmall
            color: Themes.selectedTheme.colors.appGrey
        }

        Row {
            spacing: Interface.options.spacing
            Rectangle {
                id: blank
                width: Interface.options.dialogWidth * 0.8
                height: Interface.options.columnWidth
                color: "transparent"
            }

            Text {
                id: yesButton
                text: qsTr("Yes")
                width: Interface.options.columnWidth + 10
                height: Interface.options.columnWidth
                color: "white"
                font.pixelSize: Interface.fontSize.textSizeSmall

                MouseArea {
                    id: yesMouseArea
                    anchors.fill: parent
                }
            }

            Text {
                id: noButton
                text: qsTr("No")
                width: Interface.options.columnWidth + 10
                height: Interface.options.columnWidth
                color: "white"
                font.pixelSize: Interface.fontSize.textSizeSmall

                MouseArea {
                    id: noMouseArea
                    anchors.fill: parent
                }
            }
        }
    }
}
