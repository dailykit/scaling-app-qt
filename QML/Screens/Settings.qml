import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.5
import "../Components/OrderPages"
import "../ApplicationCore/Style"

Item {

    id:setting
    width: parent.width
    height: parent.height

    Rectangle {
        color: Themes.selectedTheme.colors.extremeBlack
        width: parent.width
        height: parent.height

        Column{
            width: parent.width
            height: parent.height
            spacing: 50
        Rectangle{
            width: parent.width
            height:75
            color:Themes.selectedTheme.colors.primaryDark

            Text{
                id: settingText
                width: 300
                leftPadding  : 50
                topPadding: 15
                height: parent.height
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                text: "Settings"
                color: Themes.selectedTheme.colors.appWhite
                font.pointSize: 18
            }
        }

        Column{
            width: 600
            height: parent.height
            spacing: 30
            anchors.horizontalCenter: parent.horizontalCenter
        Row {
            id: weightAccuracyRow
            width: parent.width
            height: 50
            Text{
                id: weightAccuracy
                width: parent.width * 0.5
                height: parent.height
                text: "Weight Accuracy"
                color: Themes.selectedTheme.colors.appWhite
                font.pointSize: 18
            }
            Rectangle {
                width: parent.width * 0.5
                height: parent.height
                border.color: 'gray'
                border.width: 1
                TextInput {
                    id: weightAccuracyText
                    anchors.fill: parent
                    anchors.margins: 4
                    font.pointSize: 18
                }

            }
        }
        Row {
            id: printingTimeRow
            width: parent.width
            height: 50
            Text{
                id: printingTime
                width: parent.width * 0.5
                height: parent.height
                text: "Printing Time"
                color: Themes.selectedTheme.colors.appWhite
                font.pointSize: 18
            }
            Rectangle {
                width: parent.width * 0.5
                height: parent.height
                border.color: 'gray'
                border.width: 1
                TextInput {
                    id: printingTimeText
                    anchors.fill: parent
                    anchors.margins: 4
                    font.pointSize: 18
                }

            }
        }
        Row {
            id: simulatorRow
            width: parent.width
            height: 50
            Text{
                id: simulator
                width: parent.width * 0.5
                height: parent.height
                text: "Simulator"
                color: Themes.selectedTheme.colors.appWhite
                font.pointSize: 18
            }

        }
        Row {
            id: manualWeightEntryRow
            width: parent.width
            height: 50
            Text{
                id: manualWeightEntry
                width: parent.width * 0.5
                height: parent.height
                text: "Manual Weight Entry"
                color: Themes.selectedTheme.colors.appWhite
                font.pointSize: 18
            }
        }
        Row {
            id: printerTestRow
            width: parent.width
            height: 50
            Text{
                id: printerTest
                width: parent.width * 0.5
                height: parent.height
                text: "Printer Test"
                color: Themes.selectedTheme.colors.appWhite
                font.pointSize: 18
            }
        }
        }
        Row {
            width: 100
            height: 50
            Button {
                  text: "Ok"
               }
        }

    }
    }

    Component.onCompleted: {
        console.log("parent", parent.width, parent.height)
    }

}
