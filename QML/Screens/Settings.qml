import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.5
import "../Components/OrderPages"
import "../ApplicationCore/Style"
import "../ComponentsCore/Shapes"
import "../ComponentsCore/Buttons"

Item {

    id:setting
    width: parent.width
    height: parent.height

    Rectangle {
        color: Themes.selectedTheme.colors.extremeBlack
        width: parent.width
        height: parent.height

        Rectangle{
            id: title
            width: parent.width * 0.98
            height: parent.height * 0.089
            color:Themes.selectedTheme.colors.primaryDark
            anchors.top: parent.top
            anchors.topMargin: parent.height * 0.02
            anchors.left: parent.left
            anchors.leftMargin: parent.height * 0.02

            Text{
                id: settingText
                width: parent.width * 0.12
                height: parent.height
                anchors.left: parent.left
                anchors.leftMargin: parent.height * 0.2
                anchors.top: parent.top
                anchors.topMargin: parent.height * 0.2
                text: "Settings"
                color: Themes.selectedTheme.colors.appWhite
                font.pointSize: Interface.fontSize.textSizeSmall
            }


        }

        Column {
            id: options
            width: parent.width * 0.7
            height: parent.height * 0.3
            spacing: 30
            anchors.top: title.bottom
            anchors.topMargin: 40
            anchors.horizontalCenter: parent.horizontalCenter

            Row {
                id: weightAccuracyRow
                width: parent.width
                height: parent.height * 0.02
                Text{
                    id: weightAccuracy
                    width: parent.width * 0.5
                    height: parent.height
                    text: "Weight Accuracy"
                    color: Themes.selectedTheme.colors.appWhite
                    font.pointSize: Interface.fontSize.textSizeSmall * 0.7
                }
                Rectangle {
                    id: weigthRect
                    width: parent.width * 0.5
                    height: parent.height
                    color: Themes.selectedTheme.colors.extremeBlack

                    TextInput {
                        id: weightAccuracyText
                        width: parent.width * 0.5
                        height: parent.height
                        anchors.fill: parent
                        anchors.margins: 4
                        font.pointSize: Interface.fontSize.textSizeSmall * 0.7
                        color: Themes.selectedTheme.colors.appGrey

                        onEditingFinished: {
                            settingsModel.weightAccuracy = weightAccuracyText.text
                        }
                    }

                    HorizontalLine {
                        id: weightLine
                        anchors.bottom: parent.bottom
                        width: parent.width
                        color: Themes.selectedTheme.colors.appGrey

                    }

                }
            }
            Row {
                id: printingTimeRow
                width: parent.width
                height: parent.height * 0.02
                Text{
                    id: printingTime
                    width: parent.width * 0.5
                    height: parent.height
                    text: "Printing Time"
                    color: Themes.selectedTheme.colors.appWhite
                    font.pointSize: Interface.fontSize.textSizeSmall * 0.7
                }
                Rectangle {
                    width: parent.width * 0.5
                    height: parent.height
                    color: Themes.selectedTheme.colors.extremeBlack

                    TextInput {
                        id: printingTimeText
                        width: parent.width * 0.5
                        height: parent.height
                        anchors.fill: parent
                        anchors.margins: 4
                        font.pointSize: Interface.fontSize.textSizeSmall * 0.7
                        color: Themes.selectedTheme.colors.appGrey

                        onEditingFinished: {
                            settingsModel.weightAccuracy = printingTimeText.text
                        }
                    }

                    HorizontalLine {
                        id: printingLine
                        anchors.bottom: parent.bottom
                        width: parent.width
                        color: Themes.selectedTheme.colors.appGrey

                    }

                }
            }
            Row {
                id: simulatorRow
                width: parent.width
                height: parent.height * 0.02
                Text{
                    id: simulator
                    width: parent.width * 0.5
                    height: parent.height
                    text: "Simulator"
                    color: Themes.selectedTheme.colors.appWhite
                    font.pointSize: Interface.fontSize.textSizeSmall * 0.7
                }
                ToggleButton {
                    id: simulatorToggle

                    onClicked: {
                        settingsModel.simulator = simulatorToggle.checked
                    }
                }
            }
            Row {
                id: manualWeightEntryRow
                width: parent.width
                height: parent.height * 0.02

                Text {
                    id: manualWeightEntry
                    width: parent.width * 0.5
                    height: parent.height
                    text: "Manual Weight Entry"
                    color: Themes.selectedTheme.colors.appWhite
                    font.pointSize: Interface.fontSize.textSizeSmall * 0.7
                }
                ToggleButton {
                    id: manualWeightToggle

                    onClicked: {
                        settingsModel.manualEntry = manualWeightToggle.checked
                    }
                }
            }
            Row {
                id: printerTestRow
                width: parent.width
                height: parent.height * 0.02
                Text{
                    id: printerTest
                    width: parent.width * 0.5
                    height: parent.height
                    text: "Printer Test"
                    color: Themes.selectedTheme.colors.appWhite
                    font.pointSize: Interface.fontSize.textSizeSmall * 0.7
                }

                ToggleButton {
                    id: printerToggle

                    onClicked: {
                        settingsModel.printerTest = printerToggle.checked
                    }
                }
            }
        }

        Rectangle{
            id: saveButton
            width: parent.width * 0.08
            height: parent.height * 0.05

            anchors.top: options.bottom
            anchors.topMargin: parent.width * 0.01
            anchors.horizontalCenter: parent.horizontalCenter

            color: Themes.selectedTheme.colors.primaryDark

            Text {
                id: saveText
                text: qsTr("Save")
                font.pixelSize: Interface.fontSize.textSizeSmall * 0.7
                anchors.centerIn: parent
                color: Themes.selectedTheme.colors.appWhite
            }

            MouseArea{
                anchors.fill: parent
                onClicked: {
                    settingsModel.saveSettings()
                }
            }
        }
    }
}
