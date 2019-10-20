import QtQuick 2.0
import "../../ApplicationCore/Style"
import "../../ComponentsCore/Views"
import "../../Components/OrderPages"

Item {
    id: sectionDelegate1

    readonly property alias detailsList: details
    Column {
        width: parent.width
        height: parent.height
        spacing: 10 // TODO: remove the magic numbers


        Rectangle{
            id: title
            height: Interface.orderView.rowHeight
            width: parent.width
            color:  !model.ingredientPacked ? Themes.selectedTheme.colors.primaryDark : Themes.selectedTheme.colors.appGrey
            enabled: details.count === 1 ? !model.ingredientPacked : true

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
                    id: ingredientCount
                    height: parent.height
                    text: index + 1 + ")"
                    width: parent.width * 0.03
                    verticalAlignment: Text.AlignVCenter
                    color: Themes.selectedTheme.colors.appWhite
                    font.pixelSize: Interface.fontSize.textSizeSmall
                    fontSizeMode: Text.Fit
                }

                Text {
                    id: order
                    width: parent.width * 0.25
                    height: parent.height
                    verticalAlignment: Text.AlignVCenter
                    text: ingredientSlipName
                    color: Themes.selectedTheme.colors.appWhite
                    font.pixelSize: Interface.fontSize.textSizeSmall * 0.8
                    wrapMode: Text.WordWrap
                }

                Text {
                    id: process
                    width: parent.width * 0.3
                    height: parent.height
                    visible: details.count === 1
                    verticalAlignment: Text.AlignVCenter
                    text: ingredientProcess
                    color: Themes.selectedTheme.colors.appWhite
                    font.pixelSize: Interface.fontSize.textSizeSmall * 0.8
                }

                Text {
                    id: weight
                    width: parent.width * 0.25
                    height: parent.height
                    visible: details.count === 1
                    verticalAlignment: Text.AlignVCenter
                    text: quantity + " " + ingredientWeight
                    color: Themes.selectedTheme.colors.appWhite
                    font.pixelSize: Interface.fontSize.textSizeSmall * 0.8
                }


            }
        }

        AppListView {
            id: details

            width: parent.width
            height : details.count > 1 ? (Interface.orderView.rowHeight * details.count) + 10 : 10
            visible: details.count > 1

            model: ingredientList
            delegate: IngredientsDelegate {
                id: delegateIngredient
                height: details.count > 1 ? Interface.orderView.rowHeight : 10

                MouseArea{
                    anchors.fill: parent

                    onClicked: {
                        weighingScale.itemName = itemName
                        weighingScale.weighItem(model.ingredientDetailId, ingredientName, quantity, ingredientWeight)
                    }
                }

            }
        }
    }
}
