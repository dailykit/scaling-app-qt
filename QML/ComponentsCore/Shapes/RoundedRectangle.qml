import QtQuick 2.0

//This Component will be used for round shaped rectangles

Rectangle{
    id: root

    property real radiusCoefficient: 5
    radius: Math.min(root.width, root.height) * root.radiusCoefficient

    color: "transparent"
}
