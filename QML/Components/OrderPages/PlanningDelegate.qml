import QtQuick 2.0
import "../../ApplicationCore/Style"
import "../../ComponentsCore/Views"
import "../../Components/OrderPages"

Item {
    id: sectionDelegate1

    readonly property alias detailsList: details

  //  property color textColor: delegateIngredient.ListView.isCurrentItem ? Themes.selectedTheme.colors.extremeBlack : Themes.selectedTheme.colors.appWhite
    Column {
        width: parent.width
        height: parent.height
        spacing: 10 // TODO: remove the magic numbers


        Rectangle {
            id: title
            height: Interface.orderView.rowHeight
            width: parent.width
            color: Themes.selectedTheme.colors.appWhite

            Row {
                id: ingredientsRow

                anchors{
                    left: parent.left
                    leftMargin: parent.width * 0.03
                }

                height: Interface.orderView.rowHeight
                width: Interface.orderView.rowWidth
                spacing: Interface.orderView.ingredientRowSpacing * 0.7

                Text {
                    id: order
                    width: parent.width * 0.7
                    height: parent.height
                    verticalAlignment: Text.AlignVCenter
                    text: ingredientName
                    color: Themes.selectedTheme.colors.extremeBlack
                    font.pixelSize: Interface.fontSize.textSizeSmall * 0.8
                    wrapMode: Text.WordWrap
                }

                Text {
                    id: weight
                    width: parent.width * 0.25
                    height: parent.height
                    verticalAlignment: Text.AlignVCenter
                    text: ingredientTotalWeight + " " + "gm"
                    color: Themes.selectedTheme.colors.extremeBlack
                    font.pixelSize: Interface.fontSize.textSizeSmall * 0.8
                }

            }
        }

        AppListView {
            id: details

            width: parent.width
            height: Interface.orderView.rowHeight * details.count

            interactive : false

            model: processList
            delegate: ProcessPlanDelegate {
                id: delegateIngredientProcess

                MouseArea{
                    anchors.fill: parent

                    onClicked: {
                        details.currentIndex = index
                        planningItems.getItems(ingredientProcess, ingredientName, ingredientTotalWeight)
                        loader.source = Qt.resolvedUrl("../../Screens/PlanViewItemList.qml")

                    }
                }
            }
        }
    }
}
