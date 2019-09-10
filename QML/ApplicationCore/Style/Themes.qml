import QtQuick 2.0
pragma Singleton
import "Themes"

// Different themes can be selected, all the properties
// will automatically get updated without changing the code, user has to write Themes.selectedTheme.<..>

QtObject {
    id: root
    readonly property var selectedTheme: style[0]

    readonly property var style: [dark]

    property var dark: Dark{}

}
