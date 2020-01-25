import QtQuick 2.0
import "../../ComponentsCore/Views"

DialogView {
    id: reprintDialog

    labelText: qsTr("Are you sure you want to Delete this ingredient")
    titleText: qsTr("Delete Label")

    yesButton.onClicked: console.log("Yes Clicked")
    noButton.onClicked: console.log("No Clicked")
}
