import QtQuick 2.0

import "../Components/OrderPages"
import "../ComponentsCore/Views"
import "../ComponentsCore/Shapes"
import "../ApplicationCore/Style"

Item {
    id: root

    property variant itemModel
    property string ingredientName
    property int itemIndex

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
                text: qsTr("All Orders")
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

        RecentTabsPlanViewList {
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
            id: name
            height: parent.height
            width: parent.width * 0.5
            anchors.left: imageRectangle.right
            anchors.leftMargin: 20
            text: mainModel.planViewItemModel.ingredientName
            color: Themes.selectedTheme.colors.extremeBlack
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: Interface.fontSize.textSizeSmall
        }


        Text {
            id: weight
            height: parent.height
            width: parent.width * 0.03
            anchors.left: name.right
            anchors.leftMargin: 20
            text: mainModel.planViewItemModel.totalWeight + " gm"
            color: Themes.selectedTheme.colors.extremeBlack
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: Interface.fontSize.textSizeSmall
        }
    }

    PlanningItemsList {
        id: allItems

        width: parent.width
        height: Interface.orderView.rowHeight

        anchors.top: idOrderNumber.bottom
        anchors.topMargin: parent.height * 0.02
        recentList.model: itemModel
        ingredientName: ingredientName
    }

    RoundedRectangle {
        id: listRect

        width: parent.width
        height: parent.height * 0.75
        color: Themes.selectedTheme.colors.primaryDark
        radius: 15
        anchors.top: allItems.bottom
        anchors.topMargin: parent.height * 0.02

        AppListView {
            id: planningViewList
            anchors.fill: parent

            width: parent.width * 0.8
            height: parent.height * 0.75

            model: mainModel.planViewItemModel
            header: headerComponent

            delegate: PlanViewItemDelegate {
                id: planItemDelegate
                height: Interface.orderView.rowHeight * 1.4
                width: parent.width

                MouseArea {
                    height: Interface.orderView.rowHeight
                    width: Interface.orderView.rowWidth * 0.8
                    enabled: !optionsVisible
                    propagateComposedEvents: true

                    onClicked: {
                        planningViewList.currentIndex = index
                        mainModel.weighingScale.itemName = itemName
                        if(orderId !== "") {
                        mainModel.weighingScale.orderId = orderId
                        }
                        mainModel.weighingScale.weighItem(ingredientDetailId, mainModel.planViewItemModel.ingredientName, ingredientWeight, "gm")
                    }
                }
            }
        }
    }

    Component {
        id: headerComponent

        Row {
            id: ingredientsRow

            anchors{
                left: parent.left
                leftMargin: parent.width * 0.07
            }

            height: Interface.orderView.rowHeight
            width: Interface.orderView.rowWidth
            spacing: Interface.orderView.ingredientRowSpacing * 0.7

            Text {
                id: name
                height: parent.height
                text: "Item Name"
                width: parent.width * 0.32
                verticalAlignment: Text.AlignVCenter
                color: Themes.selectedTheme.colors.primary
                font.pixelSize: Interface.fontSize.textSizeSmall * 0.7
                fontSizeMode: Text.Fit
                elide: Text.Left
            }

            Text {
                id: orderIdd
                width: parent.width * 0.33
                height: parent.height
                verticalAlignment: Text.AlignVCenter
                text: "Order Id"
                color: Themes.selectedTheme.colors.primary
                font.pixelSize: Interface.fontSize.textSizeSmall * 0.7
                elide: Text.Left
            }

            Text {
                id: weight
                width: parent.width * 0.12
                height: parent.height
                verticalAlignment: Text.AlignVCenter
                text: "Weight"
                color: Themes.selectedTheme.colors.primary
                font.pixelSize: Interface.fontSize.textSizeSmall * 0.7
                elide: Text.Left
            }

            Text {
                id: options
                width: parent.width * 0.15
                height: parent.height
                verticalAlignment: Text.AlignVCenter
                text: "Options"
                color: Themes.selectedTheme.colors.primary
                font.pixelSize: Interface.fontSize.textSizeSmall * 0.7
                elide: Text.Left
            }
        }
    }
}
