import QtQuick 2.0
import "../../ApplicationCore/Style"
import "../../ComponentsCore/Views"
import "../../Components/OrderPages"
import "../../Components/OptionPages"
Item {
    id: sectionDelegate1

    readonly property alias detailsList: details
    property color textColor: delegateIngredient.ListView.isCurrentItem ? Themes.selectedTheme.colors.extremeBlack : Themes.selectedTheme.colors.appWhite
    property bool optionsVisible: false

    Connections {
        target: mainModel.ingredientsModel

        onIngredientIndexChanged: {
            if(delegateIngredient.ListView.isCurrentItem)
                details.currentIndex = ingredientIndex
        }
    }
    Column {
        id: columnIngredient
        width: parent.width
        height: parent.height
        spacing: parent.width * 0.01
        anchors.centerIn: parent

        Rectangle{
            id: title
            height: Interface.orderView.rowHeight
            width: parent.width
            color: delegateIngredient.ListView.isCurrentItem  ? "white" : !model.ingredientPacked ? Themes.selectedTheme.colors.primaryDark : Themes.selectedTheme.colors.appBlack

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
                    color: textColor
                    font.pixelSize: Interface.fontSize.textSizeSmall
                    fontSizeMode: Text.Fit
                }

                Text {
                    id: order
                    width: parent.width * 0.22
                    height: parent.height
                    verticalAlignment: Text.AlignVCenter
                    text: ingredientSlipName
                    color: textColor
                    font.pixelSize: Interface.fontSize.textSizeSmall * 0.8
                    wrapMode: Text.WordWrap
                }

                Rectangle {
                    width: parent.width * 0.25
                    height: parent.height
                    color: "transparent"
                    Text {
                        id: process
                        width: parent.width
                        height: parent.height
                        visible: details.count === 1
                        verticalAlignment: Text.AlignVCenter
                        text: ingredientProcess
                        color: textColor
                        font.pixelSize: Interface.fontSize.textSizeSmall * 0.8
                    }
                }
                Rectangle {
                    width: parent.width * 0.25
                    height: parent.height
                    color: "transparent"
                    Text {
                        id: weight
                        width: parent.width * 0.25
                        height: parent.height
                        visible: details.count === 1 && !optionsVisible
                        verticalAlignment: Text.AlignVCenter
                        text: quantity.toFixed(2) + " " + ingredientWeight
                        color: textColor
                        font.pixelSize: Interface.fontSize.textSizeSmall * 0.8
                    }
                }

                Text {
                    id: optionsIcon
                    width: parent.width * 0.2
                    height: parent.height
                    verticalAlignment: Text.AlignVCenter
                    text: Images.leftArrow
                    color: textColor
                    font.pixelSize: Interface.fontSize.textSizeSmall * 0.8
                    visible: !optionsVisible

                    MouseArea {
                        anchors.fill: parent

                        onClicked: {
                            optionsVisible = true

                        }
                    }
                }
            }

            OrderOptions {
                id: optionsPage
                height: parent.height
                width: parent.width * 0.45
                visible: optionsVisible

                anchors{
                    right: parent.right
                    rightMargin: parent.width * 0.03
                    top: parent.top
                    topMargin: parent.width * 0.015
                }

                textColor: textColor

                collapse.onClicked: {
                    optionsVisible = false
                }

                reprint.onClicked: {
                    var component = Qt.createComponent("../../Components/OptionPages/ReprintDialog.qml")
                    if(component.status === Component.Ready) {
                        var dialog = component.createObject(sectionDelegate1)
                        dialog.open()
                        optionsVisible = false
                    } else
                        console.error(component.errorString())
                }

                repack.onClicked: {
                    var component = Qt.createComponent("../../Components/OptionPages/RepackDialog.qml")
                    if(component.status === Component.Ready) {
                        var dialog = component.createObject(sectionDelegate1,  {itemName: mainModel.ingredientsModel.itemName, ingredientName:ingredientSlipName, ingredientDetailId: ingredientDetailId
                                                           ,orderId: mainModel.weighingScale.orderId, ingredientQuantity: quantity, ingredientWeight: "gm"})
                        dialog.open()
                        optionsVisible = false
                    } else
                        console.error(component.errorString())
                }

                deleteIngredient.onClicked: {
                    var component = Qt.createComponent("../../Components/OptionPages/DeleteIngredientDialog.qml")
                    if(component.status === Component.Ready) {
                        var dialog = component.createObject(sectionDelegate1, {ingredientId: ingredientId})
                        dialog.open()
                        optionsVisible = false
                    } else
                        console.error(component.errorString())
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
                id: delegateIngredientInternal
                property variant myData: model
                height: details.count > 1 ? Interface.orderView.rowHeight : 10

                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        details.currentIndex = index
                        mainModel.weighingScale.ingredientName = ingredientName
                        mainModel.weighingScale.weighItem(model.ingredientDetailId, ingredientName, quantity, ingredientWeight)
                    }
                }
            }

            Component.onCompleted: details.currentIndex = -1
        }

        Connections {
            target: trialRect
            onIndexChanged:{
                if(index1 !== index)
                    detailsList.currentIndex = -1
                else if(index1 === index) {
                    if(details.count > 1) {
                        mainModel.weighingScale.ingredientName =  details.currentItem.myData.ingredientName
                        mainModel.weighingScale.weighItem( details.currentItem.myData.ingredientDetailId,  details.currentItem.myData.ingredientName,  details.currentItem.myData.quantity,  details.currentItem.myData.ingredientWeight)
                    }
                }
            }
        }
    }
}
