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
        spacing: parent.width * 0.009

        Rectangle {
            id: imageOrderRectangle

            height: parent.height
            width: parent.width * 0.09
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

        RecentTabsList {
            id: recentList

            width: parent.width * 0.8
            height: Interface.orderView.rowHeight
        }
    }

    RoundedRectangle {
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

    ItemsList {
        id: allItems

        width: parent.width
        height: Interface.orderView.rowHeight

        anchors.top: idOrderNumber.bottom
        anchors.topMargin: parent.height * 0.02
    }


    AppListView {
        id: trialRect

        anchors.top: allItems.bottom
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
                    weighingScale.itemName = itemName
                    weighingScale.weighItem(ingredientDetailId, ingredientSlipName, quantity, ingredientWeight)
                }
            }

        }

    }
}
