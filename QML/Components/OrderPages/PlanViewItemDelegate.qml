import QtQuick 2.0
import "../../ApplicationCore/Style"
import "../../ComponentsCore/Views"
import "../../Components/OrderPages"

Item {
    id: root

    property color textColor: planItemDelegate.ListView.isCurrentItem ? Themes.selectedTheme.colors.extremeBlack : Themes.selectedTheme.colors.appWhite
    Column {
        width: parent.width * 0.98
        height: parent.height
        spacing: 10 // TODO: remove the magic numbers
        anchors.centerIn: parent



        Rectangle{
            id: title
            height: Interface.orderView.rowHeight * 1.2
            width: parent.width
            color: planItemDelegate.ListView.isCurrentItem ? Themes.selectedTheme.colors.appWhite : Themes.selectedTheme.colors.appBlack

            Row {
                id: ingredientsRow

                anchors{
                    left: parent.left
                    leftMargin: parent.width * 0.02
                }

                height: Interface.orderView.rowHeight
                width: Interface.orderView.rowWidth
                spacing: Interface.orderView.ingredientRowSpacing * 0.7

                Text {
                    id: ingredientCount
                    height: parent.height
                    text: index + 1 + ")"
                    width: parent.width * 0.03
                    verticalAlignment: Text.AlignVCenter
                    color: textColor
                    font.pixelSize: Interface.fontSize.textSizeSmall
                    fontSizeMode: Text.Fit
                }

                Text {
                    id: item
                    width: parent.width * 0.32
                    height: parent.height
                    verticalAlignment: Text.AlignVCenter
                    text: itemName
                    color: textColor
                    font.pixelSize: Interface.fontSize.textSizeSmall * 0.98
                    elide: Text.ElideRight
                }

                Text {
                    id: orderNo
                    width: parent.width * 0.33
                    height: parent.height
                    verticalAlignment: Text.AlignVCenter
                    text: orderId
                    color: textColor
                    font.pixelSize: Interface.fontSize.textSizeSmall * 0.98
                    elide: Text.ElideRight
                }

                Text {
                    id: weight
                    width: parent.width * 0.12
                    height: parent.height
                    verticalAlignment: Text.AlignVCenter
                    text: ingredientWeight + " " + "gm"
                    color: textColor
                    font.pixelSize: Interface.fontSize.textSizeSmall * 0.98
                }

                Text {
                    id: optionsIcon
                    width: parent.width * 0.2
                    height: parent.height
                    verticalAlignment: Text.AlignVCenter
                    text: Images.leftArrow
                    color: textColor
                    font.pixelSize: Interface.fontSize.textSizeSmall * 0.8
               //     visible: !optionsVisible

                    MouseArea {
                        anchors.fill: parent

                        onClicked: {

                        }
                    }
                }
            }
        }
    }
}
