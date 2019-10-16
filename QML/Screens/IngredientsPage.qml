import QtQuick 2.0

import "../Components/OrderPages"
import "../ComponentsCore/Views"
import "../ComponentsCore/Shapes"
import "../ApplicationCore/Style"

Item {
    id: root

    property int orderNumber
    property string itemName


    Row {
        id: allOrders
        anchors.top: parent.top

        height: Interface.orderView.rowHeight
        width: parent.width
        spacing: 10

        Rectangle {
            id: imageOrderRectangle

            height: parent.height
            width: parent.width * 0.1
            color: "transparent"
            Image {
                id: orderImages

                height: parent.height * 0.8
                width: parent.width * 0.7
                source: Images.orderImage
                anchors.centerIn: parent
            }
        }

        RoundedRectangle{
            id: orderId

            width: allOrderText.contentWidth + (parent.width * 0.04)
            height: Interface.orderView.rowHeight
            color: Themes.selectedTheme.colors.appWhite

            Text {
                id: allOrderText
                anchors.fill: parent
                text: qsTr("All Orders - 12")
                color: Themes.selectedTheme.colors.extremeBlack
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: Interface.fontSize.textSizeSmall
            }

            MouseArea {
                id: allOrderPage

                anchors.fill: parent

                onClicked: {
                    loader.source = Qt.resolvedUrl("OrderList.qml")
                }
            }

        }

        RoundedRectangle{
            id: crossOne

            width: parent.width * 0.1
            height: Interface.orderView.rowHeight
            color: Themes.selectedTheme.colors.primaryDark

            Text {
                id: crossOneText
                height: parent.height
                width: parent.width

                text: qsTr("x")
                color: Themes.selectedTheme.colors.appWhite
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: Interface.fontSize.textSizeSmall
            }
            MouseArea{
                id: clickArea
                anchors.fill: parent
            }

        }


        RoundedRectangle{
            id: orderIdBack

            width: parent.width * 0.1
            height: Interface.orderView.rowHeight
            color: Themes.selectedTheme.colors.primaryDark

            Text {
                id: orderIdText
                height: parent.height
                width: parent.width

                text: qsTr("3")
                color: Themes.selectedTheme.colors.appWhite
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: Interface.fontSize.textSizeSmall
            }

        }

        RoundedRectangle{
            id: crossTwo

            width: parent.width * 0.1
            height: Interface.orderView.rowHeight
            color: Themes.selectedTheme.colors.primaryDark

            Text {
                id: crossTwoText
                height: parent.height
                width: parent.width

                text: qsTr("x")
                color: Themes.selectedTheme.colors.appWhite
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: Interface.fontSize.textSizeSmall
            }
            MouseArea{
                id: clickAreaTwo
                anchors.fill: parent
            }

        }


        RoundedRectangle{
            id: orderNumberBack

            width: parent.width * 0.1
            height: Interface.orderView.rowHeight
            color: Themes.selectedTheme.colors.primaryDark

            Text {
                id: orderNumberText
                height: parent.height
                width: parent.width

                text: qsTr("27")
                color: Themes.selectedTheme.colors.appWhite
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: Interface.fontSize.textSizeSmall
            }

        }
    }

    RoundedRectangle{
        id: idOrderNumber

        width: parent.width
        height: Interface.orderView.rowHeight
        color: Themes.selectedTheme.colors.appWhite
        radiusCoefficient: 5
        anchors.top: allOrders.bottom
        anchors.topMargin: parent.height * 0.02


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

        anchors.top: idOrderNumber.bottom
        anchors.topMargin: parent.height * 0.02

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
