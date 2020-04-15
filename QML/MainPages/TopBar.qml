import QtQuick 2.0
import "../ApplicationCore/Style"
import "../Screens/"
Rectangle {

    readonly property alias recentAppsList: recentAppsList

    Row {
        id: topBar

        spacing: 20

        Rectangle {
            id: emptyRect


            width: 10
            height: 10
        }

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


        Rectangle {
            id: launchPadRect

            width: Interface.logo.iconSize
            height: Interface.logo.iconSize

            Image {
                id: launchPadImage

                anchors.fill: parent
                source: Images.launchPad
            }
            MouseArea{
                id: launch
                anchors.fill: parent
                onReleased: {

                    stackView.push(Qt.resolvedUrl("LandingPage.qml"))

                }
            }
        }

//        Text {
//            id: appName

//            width: parent.width * 0.2
//            height: parent.height * 0.8

//            verticalAlignment: Text.AlignHCenter
//            text: qsTr("DAILYKIT")
//            color: Themes.selectedTheme.colors.appWhite
//            font.pixelSize: Interface.fontSize.textSizeSmall
//        }

        RecentAppsList {
            id: recentAppsList

            width: parent.width * 0.8
            height: parent.height

        }


        Text {
            id: menu

            width: Interface.options.iconSize
            height: Interface.options.iconSize

            verticalAlignment: Text.AlignHCenter
            text: Images.menu
            color: Themes.selectedTheme.colors.appGrey
            font.pixelSize: Interface.fontSize.textSizeSmall
            font.bold: true
        }

        Text {
            id: userIcon

            width: Interface.options.iconSize
            height: Interface.options.iconSize

            verticalAlignment: Text.AlignHCenter
            text: Images.serving
            color: Themes.selectedTheme.colors.appGrey
            font.pixelSize: Interface.fontSize.textSizeSmall
            font.bold: true

            MouseArea  {
                anchors.fill: parent

                onClicked: {
                    userIcon.color = Themes.selectedTheme.colors.appGrey
                    loginAccess.sendLogoutRequest()
                }

                onReleased: {
                    userIcon.color = Themes.selectedTheme.colors.appWhite
                }
            }
        }

        Text {
            id: userName

            width: Interface.options.iconSize
            height: Interface.options.iconSize

            verticalAlignment: Text.AlignHCenter
            text: loginAccess.userName
            color: Themes.selectedTheme.colors.appGrey
            font.pixelSize: Interface.fontSize.textSizeSmall
            font.bold: true


        }
    }
}

