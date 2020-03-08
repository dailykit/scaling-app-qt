import QtQuick 2.0
import QtQuick.Controls 2.5

import "../../ApplicationCore/Style"

Switch {
    id: control

    indicator: Rectangle {
        implicitWidth: Interface.toggleButtons.toggleRectangleWidth
        implicitHeight: Interface.toggleButtons.toggleRectangleHeight
        x: control.leftPadding
        y: parent.height / 2 - height / 2
        radius: 13
        color: control.checked ? Themes.selectedTheme.colors.cardViewGreen : Themes.selectedTheme.colors.appGrey
        border.color: Themes.selectedTheme.colors.primaryDark

        Rectangle {
            x: control.checked ? parent.width - width : 0
            width:  Interface.toggleButtons.toggleCircleWidth
            height: Interface.toggleButtons.toggleCircleHeight
            radius: 13
            color: control.checked ? Themes.selectedTheme.colors.cardViewGreen : Themes.selectedTheme.colors.appGrey
            border.color: Themes.selectedTheme.colors.primaryDark
        }
    }
}
