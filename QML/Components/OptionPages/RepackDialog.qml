import QtQuick 2.0
import "../../ComponentsCore/Views"

DialogView {
    id: repackDialog

    property string itemName
    property string orderId
    property string ingredientName
    property string ingredientWeight // gms, kilos
    property string ingredientDetailId
    property string ingredientQuantity

    labelText: qsTr("Are you sure you want to Repack this ingredient")
    titleText: qsTr("Repack Label")

    yesButton.onClicked: {
        weighingScale.itemName = itemName
        weighingScale.orderId = orderId
        weighingScale.weighItem(ingredientDetailId, ingredientName, ingredientQuantity, ingredientWeight)
        repackDialog.close()
    }

    noButton.onClicked: repackDialog.close()
}
