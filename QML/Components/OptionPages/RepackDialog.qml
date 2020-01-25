import QtQuick 2.0
import "../../ComponentsCore/Views"

DialogView {
    id: reprintDialog

    labelText: qsTr("Are you sure you want to Repack this ingredient")
    titleText: qsTr("Repack Label")

    yesButton.onClicked: console.log("Yes Clicked")
    noButton.onClicked: console.log("No Clicked")
}
