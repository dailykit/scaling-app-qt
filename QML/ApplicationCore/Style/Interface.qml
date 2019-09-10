pragma Singleton
import QtQuick 2.0
import QtQuick.Window 2.2

QtObject{
    id: root


    readonly property real screenWidth: Screen.width
    readonly property real screenHeight: Screen.height

    readonly property real refScreenWidth: 1280
    readonly property real refScreenHeight: 800

    function hscale(size) {
        return Math.round(size * (screenWidth / refScreenWidth))
    }

    function vscale(size) {
        return Math.round(size * (screenHeight / refScreenHeight))
    }

    function tscale(size) {
        return Math.round((hscale(size) + vscale(size)) / 2)
    }

    readonly property QtObject fontSize: QtObject {
        readonly property real textSizeSmall: tscale(30)
        readonly property real textSizeMedium: tscale(38)
        readonly property real textSizeLarge: tscale(45)
    }


    readonly property QtObject orderView: QtObject {
        readonly property real ingredientRowSpacing: hscale(15)
        readonly property real rowWidth: hscale(430)
        readonly property real rowHeight: vscale(30)
    }


}
