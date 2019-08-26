import QtQuick 2.0

// This component to be used for drawing a horizontal line

Rectangle {
    id: root

    property alias length: root.width
    property alias thickness: root.height

    height: 1


}
