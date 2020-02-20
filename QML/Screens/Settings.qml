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

    property double weight: 0.0
    property int printing: 0

    Rectangle {
        color: Themes.selectedTheme.colors.extremeBlack
        width: parent.width
        height: parent.height

        Rectangle{
            id: title
            width: parent.width * 0.98
            height: parent.height * 0.089
            color: Themes.selectedTheme.colors.primaryDark
            anchors.top: parent.top
            anchors.topMargin: parent.height * 0.02
            anchors.left: parent.left
            anchors.leftMargin: parent.height * 0.02

            Button{
                id: back

                width: parent.width * 0.04
                height: parent.height * 0.6
                text: "Back"
                background: Rectangle {
                    implicitWidth: parent.width * 0.04
                    implicitHeight: parent.height * 0.6
                    color: back.down ? Themes.selectedTheme.colors.primaryDark : Themes.selectedTheme.colors.appGrey
                    border.color: "#26282a"
                    border.width: 1
                    radius: 4
                }
                contentItem: Text {
                    text: back.text
                    font: back.font
                    opacity: enabled ? 1.0 : 0.3
                    color: Themes.selectedTheme.colors.extremeBlack
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }

                anchors.left: parent.left
                anchors.leftMargin: parent.height * 0.2
                anchors.top: parent.top
                anchors.topMargin: parent.height * 0.19
                onClicked: stackView.pop()
            }

            Text{
                id: settingText
                width: parent.width * 0.12
                height: parent.height
                anchors.left: back.right
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
                height: parent.height * 0.09
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
                        anchors.fill: parent
                        font.pointSize: Interface.fontSize.textSizeSmall * 0.7
                        color: Themes.selectedTheme.colors.appWhite
                        text: weight

                        onTextEdited: {
                            mainModel.settingsModel.weightAccuracy = weightAccuracyText.text
                        }
                    }

                    HorizontalLine {
                        id: weightLine
                        anchors.bottom: weightAccuracyText.bottom
                        width: parent.width
                        color: Themes.selectedTheme.colors.appGrey

                    }
                }
            }
            Row {
                id: printingTimeRow
                width: parent.width
                height: parent.height * 0.09
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
                        font.pointSize: Interface.fontSize.textSizeSmall * 0.7
                        color: Themes.selectedTheme.colors.appWhite
                        text: printing

                        onTextEdited: {
                            mainModel.settingsModel.printingTime = printingTimeText.text
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
                height: parent.height * 0.09
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
                    checked: mainModel.settingsModel.simulator

                    onClicked: {
                        mainModel.settingsModel.simulator = simulatorToggle.checked
                    }
                }
            }
            Row {
                id: manualWeightEntryRow
                width: parent.width
                height: parent.height * 0.09

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
                    checked: mainModel.settingsModel.manualEntry

                    onClicked: {
                        mainModel.settingsModel.manualEntry = manualWeightToggle.checked
                    }
                }
            }
            Row {
                id: printerTestRow
                width: parent.width
                height: parent.height * 0.09
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
                    checked: mainModel.settingsModel.printerTest

                    onClicked: {
                        mainModel.settingsModel.printerTest = printerToggle.checked
                    }
                }
            }
        }

        Button {
            id: saveButton
            width: parent.width * 0.08
            height: parent.height * 0.05

            anchors.top: options.bottom
            anchors.topMargin: parent.width * 0.05
            anchors.horizontalCenter: parent.horizontalCenter
            background: Rectangle {
                implicitWidth: parent.width * 0.08
                implicitHeight: parent.height * 0.05
                color: saveButton.down ? Themes.selectedTheme.colors.primaryDark : Themes.selectedTheme.colors.appGrey
                border.color: "#26282a"
                border.width: 1
                radius: 4
            }

            contentItem: Text {
                text: saveButton.text
                font: saveButton.font
                opacity: enabled ? 1.0 : 0.3
                color: Themes.selectedTheme.colors.extremeBlack
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            text: qsTr("Save")

            font.pixelSize: Interface.fontSize.textSizeSmall * 0.7


            onClicked: {
                mainModel.settingsModel.saveSettings()
            }

        }
    }

    Component.onCompleted: {
        weight = mainModel.settingsModel.weightAccuracy
        printing = mainModel.settingsModel.printingTime
    }
}
