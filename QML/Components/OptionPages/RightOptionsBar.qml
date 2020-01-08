import QtQuick 2.0

import "../../ApplicationCore/Style"
import "../../ComponentsCore/Buttons"

Column {
    id: root

    spacing: parent.width * 0.099
    width: parent.width
    height: parent.height

    readonly property alias settings: settings
    readonly property alias inventory: inventory
    readonly property alias planning: planning
    Rectangle{
        id: blank
        color: "transparent"
        width: parent.width
        height: Interface.options.iconSize * 0.5

    }

    Text {
        id: quickControlsText
        width: parent.width
        height: Interface.options.iconSize
        text: qsTr("Quick Controls")
        color: Themes.selectedTheme.colors.appWhite
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        wrapMode: Text.WordWrap
        font.pixelSize: Interface.fontSize.textSizeExtraSmall
        font.bold: true
    }

    VerticalViewButton {
        id: inventory

        width: parent.width
        height: parent.width

        icon.width: Interface.options.iconSize
        icon.height: Interface.options.iconSize
        icon.text: Images.inventory
        icon.color: Themes.selectedTheme.colors.appWhite
        icon.font.pixelSize: Interface.options.iconSize * 0.9

        text.text: qsTr("Inventory")
        text.color: Themes.selectedTheme.colors.appWhite
        text.verticalAlignment: Text.AlignVCenter
        text.wrapMode: Text.WordWrap
        text.font.pixelSize: Interface.fontSize.textSizeExtraSmall
        text.width: Interface.options.iconSize
        text.height: Interface.options.iconSize
        text.font.bold: true
    }

    VerticalViewButton {
        id: planning

        width: parent.width
        height: parent.width

        icon.width: Interface.options.iconSize
        icon.height: Interface.options.iconSize
        icon.text: Images.planning
        icon.color: Themes.selectedTheme.colors.appWhite
        icon.font.pixelSize: Interface.options.iconSize

        text.text: qsTr("Planning")
        text.color: Themes.selectedTheme.colors.appWhite
        text.verticalAlignment: Text.AlignVCenter
        // text.wrapMode: Text.WordWrap
        text.font.pixelSize: Interface.fontSize.textSizeExtraSmall
        text.width: Interface.options.iconSize
        text.height: Interface.options.iconSize
        text.font.bold: true
        state: "planning"

        states: [
            State {
                name: "planning"
                PropertyChanges { target: planning; icon.text: Images.planning
                    text.text: qsTr("Planning")}
            },
            State {
                name: "real"
                PropertyChanges { target: planning; icon.text: Images.realTime
                    text.text: qsTr("Real time")
                }
            }

        ]
    }

    VerticalViewButton {
        id: settings

        width: parent.width
        height: parent.width

        icon.width: Interface.options.iconSize
        icon.height: Interface.options.iconSize
        icon.text: Images.settings
        icon.color: Themes.selectedTheme.colors.appWhite
        icon.font.pixelSize: Interface.options.iconSize * 0.9

        text.text: qsTr("Settings")
        text.color: Themes.selectedTheme.colors.appWhite
        text.verticalAlignment: Text.AlignVCenter
        text.wrapMode: Text.WordWrap
        text.font.pixelSize: Interface.fontSize.textSizeExtraSmall
        text.width: Interface.options.iconSize
        text.height: Interface.options.iconSize
        text.font.bold: true

    }

}
