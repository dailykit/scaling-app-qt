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
        readonly property real textSizeExtraSmall: screenWidth * (16 / 9) * 0.005
        readonly property real textSizeSmall: screenWidth * (16 / 9) * 0.007
        readonly property real textSizeMedium: screenWidth * (16 / 9) * 0.01
        readonly property real textSizeLarge: tscale(45)
    }


    readonly property QtObject orderView: QtObject {
        readonly property real ingredientRowSpacing: hscale(15)
        readonly property real recentListWidth: screenWidth * 0.09
        readonly property real rowWidth: screenWidth * 0.4
        readonly property real rowHeight: screenHeight * 0.05
        readonly property real orderIconsHeight: screenHeight * 0.01
        readonly property real orderIconsWidth: screenWidth * 0.01
    }

     readonly property QtObject options: QtObject {
        readonly property real iconSize: screenWidth * 0.018
        readonly property real spacing: screenWidth * 0.007
        readonly property real dialogWidth: screenWidth *  0.3
        readonly property real dialogHeight: screenHeight * 0.09
        readonly property real columnWidth: screenWidth * 0.02
    }

    readonly property QtObject logo: QtObject {
       readonly property real iconSize: screenWidth * 0.02

   }

}
