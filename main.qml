import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    visible: true
    width: 1240
    height: 550
    color: "black"

    Rectangle {
        id: idTopMargin
        height: 2
        width: parent.width
        color: "grey"
        anchors{

            top: parent.top
            topMargin: 40
        }
    }

    Rectangle {
        id: idleftMargin
        height: parent.height
        width: 2
        color: "grey"
        anchors{
            left: parent.left
            leftMargin: parent.width * 0.055
            top: idTopMargin.bottom
            //topMargin: parent.height * 0.05
        }
    }

    WeighingScale{
        id: idWeightDetails
        height: parent.height * 0.4
        width: parent.width * 0.4

        anchors{
            top: parent.top
            topMargin: parent.height * 0.09
            left: idleftMargin.right
            leftMargin: parent.width * 0.03
        }

    }
    Rectangle {
        id: trialRect
        width: parent.width * 0.4
        height: parent.height * 0.9
        anchors {
            top: parent.top
            topMargin: parent.height * 0.09
            left: idWeightDetails.right
            leftMargin: parent.width * 0.03
        }
        color: "grey"
    }

    Rectangle {
        id: idRightMargin
        height: parent.height
        width: 2
        color: "grey"
        anchors{
            right: parent.right
            rightMargin: parent.width * 0.055
            top: idTopMargin.bottom
        }
    }
}
