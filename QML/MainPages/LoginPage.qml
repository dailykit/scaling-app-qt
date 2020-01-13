import QtQuick 2.0
import QtQuick.Controls 2.5
import "../ApplicationCore/Style"

Rectangle {

    id: rootLogin
    height: parent.height
    width: parent.width
    color: Themes.selectedTheme.colors.primary

    Column{

        anchors.centerIn: parent

        width: parent.width * 0.2
        height: parent.height * 0.47

        spacing: 20

        Rectangle {
            id: logoRect

            height: parent.height * 0.3
            width: parent.width
            color: "transparent"

            Image {
                id: logoImage

                source: Images.logo
                height: parent.height * 0.9
                width: parent.width * 0.4
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }

        Text{
            id: nameText

            height: parent.height * 0.002
            width: parent.width * 0.007

            text: qsTr("UserName")
            color: Themes.selectedTheme.colors.cardViewRed
            font.pixelSize: Interface.fontSize.textSizeExtraSmall * 0.8
            horizontalAlignment: Text.AlignLeft
        }

        Rectangle {
            id: nameRect

            width: parent.width * 0.95
            height: parent.height * 0.08
            color: "transparent"
            border.width: 1
            border.color: Themes.selectedTheme.colors.primaryDark

            TextInput {
                id: nameInput

                width: parent.width * 0.9
                height: parent.height
                anchors.left: parent.left
                anchors.leftMargin: parent.width * 0.009
                verticalAlignment: Text.AlignVCenter
                color: Themes.selectedTheme.colors.extremeBlack

            }

        }

        Text{
            id: passText

            height: parent.height * 0.002
            width: parent.width * 0.007

            text: qsTr("Password")
            color: Themes.selectedTheme.colors.cardViewRed
            font.pixelSize: Interface.fontSize.textSizeExtraSmall * 0.8
            horizontalAlignment: Text.AlignLeft
        }

        Rectangle {
            id: passRect

            width: parent.width * 0.95
            height: parent.height * 0.08
            color: "transparent"
            border.width: 1
            border.color: Themes.selectedTheme.colors.primaryDark

            TextInput {
                id: passInput

                anchors.left: parent.left
                anchors.leftMargin: parent.width * 0.009
                width: parent.width * 0.9
                height: parent.height
                echoMode: TextInput.Password
                verticalAlignment: Text.AlignVCenter
                color: Themes.selectedTheme.colors.extremeBlack
            }

            Text {
                id: passShow

                text: Images.profile
                verticalAlignment: Text.AlignVCenter
                height: parent.height
                width: parent.width * 0.1
                color: Themes.selectedTheme.colors.extremeBlack
                anchors.right: parent.right
                font.pixelSize: Interface.fontSize.textSizeSmall * 0.9

                MouseArea {
                    anchors.fill: parent

                    onPressAndHold: {
                        passInput.echoMode = TextInput.Normal
                    }
                    onReleased: {
                        passInput.echoMode = TextInput.Password
                    }
                }
            }
        }


        Button {
            id: loginButton
            width: parent.width * 0.95
            height: parent.height * 0.08

            background: Rectangle {
                implicitWidth: parent.width * 0.08
                implicitHeight: parent.height * 0.05
                color: loginButton.down ? Themes.selectedTheme.colors.appGrey :Themes.selectedTheme.colors.primaryDark
                border.color: "#26282a"
                border.width: 1
                radius: parent.width * 0.05
            }

            contentItem: Text {
                text: loginButton.text
                font: loginButton.font
                opacity: enabled ? 1.0 : 0.3
                color: Themes.selectedTheme.colors.extremeBlack
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            text: qsTr("Login")

            font.pixelSize: Interface.fontSize.textSizeSmall * 0.7


            onClicked: {
                var component = Qt.createComponent(Qt.resolvedUrl("MainOrdersPage.qml"))
                if (component.status === Component.Ready) {
                    component.createObject(parent);
                    stackView.push(component)
                }
            }
        }
    }

}
