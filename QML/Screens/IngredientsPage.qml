import QtQuick 2.0

import "../Components/OrderPages"
import "../ComponentsCore/Views"
import "../ComponentsCore/Shapes"
import "../ApplicationCore/Style"

Item {
    id: root

    property int orderNumber
    property string itemName

    RoundedRectangle{
        id: orderId

        width: parent.width
        height: Interface.orderView.rowHeight
        color: Themes.selectedTheme.colors.appWhite
        radiusCoefficient: 5
        anchors.top: parent.top


        Rectangle {
            id: imageRectangle

            height: parent.height
            width: parent.width * 0.15
            color: "transparent"
            Image {
                id: user

                height: parent.height * 0.8
                width: parent.width * 0.4
                source: Images.orderImage
                anchors.centerIn: parent
            }
        }

        Text {
            id: order
            height: parent.height
            width: parent.width * 0.03
            anchors.left: imageRectangle.right
            anchors.leftMargin: 20
            text: orderNumber
            color: Themes.selectedTheme.colors.extremeBlack
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: Interface.fontSize.textSizeSmall
        }
    }


    AppListView {
        id: trialRect

        anchors.top: orderId.bottom
        anchors.topMargin: parent.height * 0.03

        width: parent.width
        height: parent.height * 0.89

        model: ingredientModel
        delegate: IngredientSectionDelegate {
            id: delegateIngredient
            height: Interface.orderView.rowHeight + detailsList.height
            width: parent.width

            MouseArea {
                anchors.fill: parent
                enabled: detailsList.count === 1
                onClicked: {
                    weighingScale.weighItem(ingredientId, itemName, ingredientSlipName, quantity, ingredientWeight)
                }
            }

        }

    }
}
