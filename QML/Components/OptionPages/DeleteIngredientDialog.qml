import QtQuick 2.0
import "../../ComponentsCore/Views"

DialogView {
    id: deleteDialog

    property string ingredientId

    labelText: qsTr("Are you sure you want to Delete this ingredient")
    titleText: qsTr("Delete Label")

    yesButton.onClicked: {
        mainModel.manipulateIngredients.deleteIngredient(ingredientId)
        deleteDialog.close()
    }

    noButton.onClicked: {
        deleteDialog.close()
    }
}
