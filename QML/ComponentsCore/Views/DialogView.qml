import QtQuick 2.0
import QtQuick.Controls 2.4

Dialog {
    id: dialog


    property string labelText
    property string titleText
    property alias yesButton: yesMouseArea
    property alias noButton: noMouseArea
    // standardButtons: Dialog.Yes | Dialog.No
    modal: true
    anchors.centerIn: Overlay.overlay
    background: Rectangle {
        implicitWidth: 400
        implicitHeight: dialog.height
        color: "grey"
    }

    contentItem : Column {
        spacing: 10
        Text {
            id: titleT
            text: titleText
            width: 30
            height: 30
            color: "white"
            font.pixelSize: 12
        }

        Label {
            text: labelText
            font.pixelSize: 14
        }

        Row {
            spacing: 10
            Rectangle {
                id: blank
                width: 300
                height: 30
                color: "transparent"
            }

            Text {
                id: yesButton
                text: qsTr("Yes")
                width: 30
                height: 30
                color: "white"
                font.pixelSize: 12

                MouseArea {
                    id: yesMouseArea
                    anchors.fill: parent
                }

            }

            Text {
                id: noButton
                text: qsTr("No")
                width: 30
                height: 30
                color: "white"
                font.pixelSize: 12

                MouseArea {
                    id: noMouseArea
                    anchors.fill: parent
                }
            }

        }

    }

}
