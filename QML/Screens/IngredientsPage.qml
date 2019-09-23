import QtQuick 2.0

import "../Components/OrderPages"
import "../ComponentsCore/Views"
import "../ComponentsCore/Shapes"
import "../ApplicationCore/Style"

Item {
    id: root

    property string orderNumber
    property string itemName

    RoundedRectangle{
        id: orderId

        width: parent.width
        height: Interface.orderView.rowHeight
        color: Themes.selectedTheme.colors.appWhite
        radiusCoefficient: 5
        anchors.top: parent.top


        Image{
            id: orderImage
            anchors.left: parent.left
            anchors.leftMargin: 20
            anchors.verticalCenter: parent.verticalCenter

            width: Interface.orderView.orderIconsWidth
            height: Interface.orderView.orderIconsHeight
            source: Images.orderImage
        }

        Text {
            id: order
            height: parent.height
            width: parent.width * 0.03
            anchors.left: orderImage.right
            anchors.leftMargin: 20
            text: orderNumber
            color: Themes.selectedTheme.colors.primaryDark
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: Interface.fontSize.textSizeSmall
        }
    }


    AppListView {
        id: trialRect

        anchors.top: orderId.bottom
        anchors.topMargin: 30

        width: parent.width
        height: parent.height * 0.7

        model: ingredientModel
        delegate: IngredientSectionDelegate {
            id: delegateIngredient
            height: Interface.orderView.rowHeight + detailsList.height
            width: parent.width

        }

    }
}
