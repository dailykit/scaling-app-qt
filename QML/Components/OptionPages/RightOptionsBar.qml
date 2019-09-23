import QtQuick 2.0

import "../../ApplicationCore/Style"
import "../../ComponentsCore/Buttons"

Column {
    id: root

    spacing: parent.width * 0.09
    width: parent.width
    height: parent.height


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
        icon.source: Images.inventory

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
        icon.source: Images.planning

        text.text: qsTr("Planning")
        text.color: Themes.selectedTheme.colors.appWhite
        text.verticalAlignment: Text.AlignVCenter
        text.wrapMode: Text.WordWrap
        text.font.pixelSize: Interface.fontSize.textSizeExtraSmall
        text.width: Interface.options.iconSize
        text.height: Interface.options.iconSize
        text.font.bold: true
    }

    VerticalViewButton {
        id: settings

        width: parent.width
        height: parent.width

        icon.width: Interface.options.iconSize
        icon.height: Interface.options.iconSize
        icon.source: Images.settings

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
