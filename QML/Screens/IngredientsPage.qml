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
            id: imagefilterRectangle

            height: Interface.orderView.rowHeight
            width: parent.width * 0.09
            color: "transparent"

            Text {
                id: filterImage

                height: parent.height
                width: parent.width
                verticalAlignment: Text.AlignVCenter
               // font.family: Images.iconfont.name
                text: Images.filterIcon
                font.pixelSize: Interface.fontSize.textSizeMedium
                color: Themes.selectedTheme.colors.appGrey
            }
        }

        RoundedRectangle{
            id: orderId

            width: allOrderText.contentWidth + (parent.width * 0.04)
            height: Interface.orderView.rowHeight
            color: Themes.selectedTheme.colors.primary

            Text {
                id: allOrderText
                anchors.fill: parent
                text: qsTr("All Orders - 12")
                color: Themes.selectedTheme.colors.appWhite
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: Interface.fontSize.textSizeSmall
            }

            MouseArea {
                id: allOrderPage

                anchors.fill: parent

                onClicked: {
                    loader.source = Qt.resolvedUrl("OrderList.qml")
                    recentTabs.setCurrentItem(-1)
                }
            }

        }

        RecentTabsList {
            id: recentList

            width: parent.width * 0.8
            height: Interface.orderView.rowHeight
        }
    }

    Rectangle {
        id: activeOrder

        width: parent.width * 0.8
        height: Interface.orderView.rowHeight * 0.5
        anchors.top: allOrders.bottom
        anchors.topMargin: parent.height * 0.01
        color: "transparent"

        Text {
            id: activeOrderText
            width: parent.width * 0.15
            height: parent.height
            verticalAlignment: Text.AlignVCenter
            text: "Active Order"
            color: Themes.selectedTheme.colors.primary
            font.pixelSize: Interface.fontSize.textSizeSmall * 0.9
            elide: Text.Left
        }
    }

    RoundedRectangle {
        id: idOrderNumber

        width: parent.width
        height: Interface.orderView.rowHeight
        color: Themes.selectedTheme.colors.appWhite
        radiusCoefficient: 5
        anchors.top: activeOrder.bottom
        anchors.topMargin: parent.height * 0.02


        Rectangle {
            id: orderImageRectangle

            height: parent.height
            width: parent.width * 0.08
            anchors.left: parent.left
            anchors.leftMargin: parent.width * 0.06
            color: "transparent"

            Text {
                id: user

                height: parent.height
                width: parent.width * 0.03
                verticalAlignment: Text.AlignVCenter
                text: Images.order
                font.pixelSize: Interface.fontSize.textSizeSmall
                color: Themes.selectedTheme.colors.extremeBlack
            }
        }

        Text {
            id: order

            height: parent.height
            width: parent.width * 0.03
            anchors.left: orderImageRectangle.right
            verticalAlignment: Text.AlignVCenter
            text: ingredientModel.orderNumber
            color: Themes.selectedTheme.colors.extremeBlack
            font.pixelSize: Interface.fontSize.textSizeSmall
        }
    }

    Rectangle {
        id: itemToPack

        width: parent.width * 0.8
        height: Interface.orderView.rowHeight * 0.5
        anchors.top: idOrderNumber.bottom
        anchors.topMargin: parent.height * 0.01
        color: "transparent"

        Text {
            id: itemToPackText
            width: parent.width * 0.15
            height: parent.height
            verticalAlignment: Text.AlignVCenter
            text: "Items to Pack"
            color: Themes.selectedTheme.colors.primary
            font.pixelSize: Interface.fontSize.textSizeSmall * 0.9
            elide: Text.Left
        }
    }

    ItemsList {
        id: allItems

        width: parent.width
        height: Interface.orderView.rowHeight

        anchors.top: itemToPack.bottom
        anchors.topMargin: parent.height * 0.02
    }

    RoundedRectangle {
        id: listRect

        width: parent.width
        height: parent.height * 0.75
        color: Themes.selectedTheme.colors.primary
        radius: 15
        anchors.top: allItems.bottom
        anchors.topMargin: parent.height * 0.02

        AppListView {
            id: trialRect


            anchors.left: parent.left
            anchors.leftMargin: parent.height * 0.05

            width: parent.width * 0.9
            height: parent.height

            header: headerComponent

            signal indexChanged(var index1)

            model: ingredientModel
            delegate: IngredientSectionDelegate {
                id: delegateIngredient
                height: Interface.orderView.rowHeight + detailsList.height
                width: parent.width

                MouseArea {
                    anchors.fill: parent
                    propagateComposedEvents: true
                    onClicked: {
                        trialRect.currentIndex = index
                        if(detailsList.count === 1) {
                            weighingScale.itemName = ingredientModel.itemName
                            weighingScale.weighItem(ingredientDetailId, ingredientSlipName, quantity, ingredientWeight)
                        } else {
                            detailsList.currentIndex = 0
                        }

                        trialRect.indexChanged(index)
                        mouse.accepted = false
                    }
                }
            }
        }
    }

    Connections {
        target: ingredientModel

        onItemIndexChanged: {
            trialRect.currentIndex = itemIndex
        }
    }


    Component {
        id: headerComponent

        Row {
            id: ingredientsRow

            anchors{
                left: parent.left
                leftMargin: parent.width * 0.05
            }

            height: Interface.orderView.rowHeight
            width: Interface.orderView.rowWidth
            spacing: Interface.orderView.ingredientRowSpacing * 0.7

            Text {
                id: name
                height: parent.height
                text: "Ingredient"
                width: parent.width * 0.3
                verticalAlignment: Text.AlignVCenter
                color: Themes.selectedTheme.colors.primaryDark
                font.pixelSize: Interface.fontSize.textSizeSmall * 0.7
                fontSizeMode: Text.Fit
                elide: Text.Left
            }

            Text {
                id: orderIdd
                width: parent.width * 0.3
                height: parent.height
                verticalAlignment: Text.AlignVCenter
                text: "Processing"
                color: Themes.selectedTheme.colors.primaryDark
                font.pixelSize: Interface.fontSize.textSizeSmall * 0.7
                elide: Text.Left
            }

            Text {
                id: weight
                width: parent.width * 0.12
                height: parent.height
                verticalAlignment: Text.AlignVCenter
                text: "Weight"
                color: Themes.selectedTheme.colors.primaryDark
                font.pixelSize: Interface.fontSize.textSizeSmall * 0.7
                elide: Text.Left
            }

            Text {
                id: options
                width: parent.width * 0.15
                height: parent.height
                verticalAlignment: Text.AlignVCenter
                text: "Options"
                color: Themes.selectedTheme.colors.primaryDark
                font.pixelSize: Interface.fontSize.textSizeSmall * 0.7
                elide: Text.Left
            }
        }

    }
}
