import QtQuick 2.0

// this component to be used to show an image and text side by side vertically

Rectangle{
    id: root

    readonly property alias icon: icon
    readonly property alias text: text

    color: "transparent"
    Image{
        id: icon

        anchors.horizontalCenter: parent.horizontalCenter
    }

    Text {
        id: text;

        anchors.top: icon.bottom

        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter


    }

    MouseArea{
        anchors.fill: parent
    }
}
