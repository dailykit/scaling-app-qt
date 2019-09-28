import QtQuick 2.11
import QtQuick.Window 2.11
import "../Components/OrderPages"
import "../ApplicationCore/Style"

Item {

    id:setting
    width: Screen.width
    height: Screen.height

    Rectangle {
        id: idIngredientRectangle
        width: parent.width
        height: parent.height * 0.3
        color: "white"
        Row {
            id: idTextColumn
            width: parent.width
            height: parent.height
            anchors {
                centerIn: parent
                leftMargin: parent.width * 0.0125
            }
            spacing: parent.height * 0.08

            Text{
                id: weightAccuracy
                width: parent.width * 0.5
                height: parent.height
                text: "Weight Accuracy"
            }

            TextInput{
                id: weightAccuracyTextField
                width: parent.width * 0.5
                height: parent.height

            }

        }

    }

}
