import QtQuick 2.0
import "../../ComponentsCore/Views"

DialogView {
    id: reprintDialog

    labelText: qsTr("Are you sure you want to Reprint this ingredient")
    titleText: qsTr("Reprint Label")

    yesButton.onClicked:  {
        reprintDialog.close()
        console.log("Yes Clicked")
    }
    noButton.onClicked: console.log("No Clicked")
}
