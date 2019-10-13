import QtQuick 2.0
import "../../ApplicationCore/Style"

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
            color: Themes.selectedTheme.colors.appWhite
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
                    text: weighingScale.orderId
                }

                Text{
                    id: idTextIngredient
                    height: parent.height * 0.3
                    font.pixelSize: idTextIngredient.height * 0.5
                    text: weighingScale.itemName
                }

                Text{
                    id: idIngredientSelected
                    height:  parent.height * 0.3
                    font.pixelSize: idIngredientSelected.height * 0.6
                    text: weighingScale.ingredientName
                }
            }

        }

        Rectangle{
            id: idShowWeight
            width: parent.width
            height: parent.height * 0.3
            color: weighingScale.weightRange === 2 ? Themes.selectedTheme.colors.cardViewRed
                                                                          : weighingScale.weightRange === 1
                                                                                ? Themes.selectedTheme.colors.cardViewGreen
                                                                                : Themes.selectedTheme.colors.cardViewYellow

            Rectangle {
                id: imageRectangleWeight

                height: parent.width * 0.07
                width: parent.width * 0.07
                color: "transparent"
                anchors{
                    left: parent.left
                    leftMargin: parent.width * 0.04
                    top: parent.top
                    topMargin: parent.height * 0.04
                }
                Image {
                    id: weight

                    height: parent.height
                    width: parent.width
                    source: Images.weight
                    anchors.centerIn: parent
                }
            }

            Text{
                id: idQuantityText
                width: idQuantityText.contentWidth
                height: parent.width * 0.3
                anchors{
                    left: parent.left
                    leftMargin: parent.width * 0.2
                    top: parent.top
                    topMargin: parent.height * 0.2
                }
                text: weighingScale.calculatedQuantity
                font.pixelSize: idGramsText.height * 0.12
            }

            Text{
                id: idGramsText
                width: idGramsText.contentWidth
                height: parent.width * 0.3
                anchors{
                    left: idQuantityText.right
                    leftMargin: parent.width * 0.008
                    top: parent.top
                    topMargin: parent.height * 0.2
                }
                text: weighingScale.weight
                font.pixelSize: idGramsText.height * 0.12
            }

            Text{
                id: idStateText
                width: parent.width* 0.3
                height:  parent.width* 0.3
                anchors{
                    left: parent.left
                    leftMargin: parent.width * 0.04
                    top: imageRectangleWeight.bottom
                    topMargin: parent.height * 0.1
                }
                text:  qsTr("Ready")
                font.pixelSize: idStateText.height * 0.09
                color: Themes.selectedTheme.colors.appWhite
            }

        }

        Rectangle{
            id: idWeightStateRectangle
            width: parent.width
            height: parent.height * 0.15

            color: Themes.selectedTheme.colors.primaryDark

            Rectangle {
                id: imageRectanglePrint

                height: parent.height
                width: parent.width * 0.15
                color: "transparent"
                anchors{
                    left: parent.left
                    leftMargin: parent.width * 0.02
                }
                Image {
                    id: printer

                    height: parent.height * 0.6
                    width: parent.width * 0.4
                    source: Images.printer
                    anchors.centerIn: parent
                }
            }

            Text {
                id: idWeightStateText
                anchors{
                    left: imageRectanglePrint.right
                    leftMargin: parent.width * 0.02
                    top: parent.top
                    topMargin: parent.height * 0.3
                }
                text: qsTr("Start Weighing")
                font.pixelSize: parent.height * 0.4
                color: Themes.selectedTheme.colors.appWhite
            }
        }

        Rectangle{
            id: idSimulator
            width: parent.width * 0.15
            height: parent.height * 0.15

            color: Themes.selectedTheme.colors.primaryDark

            Text {
                id: simulatorText
                text: qsTr("Simulator")
                font.pixelSize: parent.height * 0.4
                anchors.centerIn: parent
                color: Themes.selectedTheme.colors.appWhite
            }

            MouseArea{
                anchors.fill: parent
                onClicked: {
                    weighingScale.calculateActualWeight(weighingScale.ingredientQuantity())
                }
            }
        }

    }
}
