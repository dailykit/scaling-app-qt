import QtQuick 2.0
import QtQuick.Controls 2.5

import "../../ApplicationCore/Style"

Switch {
    id: control

    indicator: Rectangle {
        implicitWidth: 48
        implicitHeight: 20
        x: control.leftPadding
        y: parent.height / 2 - height / 2
        radius: 13
        color: control.checked ? Themes.selectedTheme.colors.cardViewRed : Themes.selectedTheme.colors.appGrey
        border.color: Themes.selectedTheme.colors.primaryDark

        Rectangle {
            x: control.checked ? parent.width - width : 0
            width: 22
            height: 20
            radius: 13
             color: control.checked ? Themes.selectedTheme.colors.cardViewRed : Themes.selectedTheme.colors.appGrey
            border.color: Themes.selectedTheme.colors.primaryDark
        }
    }
}
