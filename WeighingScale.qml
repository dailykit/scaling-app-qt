import QtQuick 2.0

Item {
    id: root

    Column {
        id: idmainWeigh
        anchors.fill: parent
        spacing: 2
        Rectangle {
            id: idIngredientRectangle
            width: parent.width
            height: parent.height * 0.3
            color: "white"
            Column {
                id: idTextColumn
                width: parent.width * 0.97
                height: parent.height
                anchors {
                    left: parent.left
                    leftMargin: parent.width * 0.0125
                }
                spacing: parent.height * 0.08

                Text{
                    id: idTextOrderId
                    width: parent.width
                    height: parent.height * 0.3
                    font.pixelSize: idTextIngredient.height * 0.5
                    text: "200012343545434"
                }

                Text{
                    id: idTextIngredient
                    height: parent.height * 0.3
                    font.pixelSize: idTextIngredient.height * 0.5
                    text: "Malai kofta"
                }

                Text{
                    id: idIngredientSelected
                    height:  parent.height * 0.3
                    font.pixelSize: idIngredientSelected.height * 0.6
                    text: "No ingredient selected"
                }
            }

        }

        Rectangle{
            id: idShowWeight
            width: parent.width
            height: parent.height * 0.3
            color: "lightgreen"

            Rectangle{
                id: idImg //temporary
                width: parent.width* 0.07
                height: parent.width* 0.07
                anchors{
                    left: parent.left
                    leftMargin: parent.width * 0.04
                    top: parent.top
                    topMargin: parent.height * 0.04
                }

                color: "blue"
            }

            Text{
                id: idGramsText
                width: parent.width* 0.3
                height: parent.width* 0.3
                anchors{
                    left: parent.left
                    leftMargin: parent.width * 0.2
                    top: parent.top
                    topMargin: parent.height * 0.2
                }
                text: "0.00 gms"
                font.pixelSize: idGramsText.height * 0.12
            }

            Text{
                id: idStateText
                width: parent.width* 0.3//50
                height:  parent.width* 0.3//50
                anchors{
                    left: parent.left
                    leftMargin: parent.width * 0.04
                    top: idImg.bottom
                    topMargin: parent.height * 0.1
                }
                text: "Ready"
                font.pixelSize: idStateText.height * 0.09
            }

//            Text {
//                id:

//            }

        }

        Rectangle{
            id: idWeightStateRectangle
            width: parent.width
            height: parent.height * 0.15

            color: "grey"

            Text {
                id: idWeightStateText
                anchors{
                    left: parent.left
                    leftMargin: parent.width * 0.07
                    top: parent.top
                    topMargin: parent.height * 0.3
                }
                text: qsTr("start weighing")
                font.pixelSize: parent.height * 0.3

            }
        }

    }
}
