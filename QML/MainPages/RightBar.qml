import QtQuick 2.0
import "../ComponentsCore/Shapes"
import "../Components/OptionPages"

Item {
    id: root

    width: parent.width
    height: parent.height

    readonly property alias options: options

    Row {
        id: rightBar
        width: parent.width
        height: parent.height

        spacing: parent.width * 0.3

        VerticalLine {
            id: idRightMargin

            height: parent.height
            width: 2
            color: "grey"

        }

        RightOptionsBar {
            id: options

            width: parent.width * 0.9
            height: parent.height
        }

    }

}
