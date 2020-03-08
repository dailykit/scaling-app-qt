import QtQuick 2.0
import "../../ApplicationCore/Style"
import "../../ComponentsCore/Views"
import "../../Components/OrderPages"
import "../../ComponentsCore/Shapes"

Item {
    id: sectionDelegate1

    readonly property alias detailsList: details

    //  property color textColor: delegateIngredient.ListView.isCurrentItem ? Themes.selectedTheme.colors.extremeBlack : Themes.selectedTheme.colors.appWhite
    Column {
        width: parent.width
        height: parent.height

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
                    font.pixelSize: Interface.fontSize.textSizeSmall
                    fontSizeMode: Text.Fit
                }

                Text {
                    id: weight
                    width: parent.width * 0.25
                    height: parent.height
                    verticalAlignment: Text.AlignVCenter
                    text: ingredientTotalWeight + " " + "gm"
                    color: Themes.selectedTheme.colors.extremeBlack
                    font.pixelSize: Interface.fontSize.textSizeSmall
                    fontSizeMode: Text.Fit
                }

            }
        }

        RoundedRectangle {
            id: externalRect

            height: Interface.orderView.rowHeight * details.count
            width: parent.width
            color: Themes.selectedTheme.colors.primary

            radius: 5

            AppListView {
                id: details

                width: parent.width
                height: parent.height

                interactive : false

                model: processList
                delegate: ProcessPlanDelegate {
                    id: delegateIngredientProcess

                    MouseArea{
                        anchors.fill: parent

                        onClicked: {
                            details.currentIndex = index
                            mainModel.planViewItemModel.getItems(ingredientProcess, ingredientName, ingredientTotalWeight)
                            loader.setSource(Qt.resolvedUrl("../../Screens/PlanViewItemList.qml"), {itemModel: processList, ingredientName: ingredientName, itemIndex: index})
                            mainModel.recentIngredients.addRecentItem(ingredientName, ingredientProcess, ingredientTotalWeight)
                        }
                    }
                }
            }
        }
    }
}
