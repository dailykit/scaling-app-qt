import QtQuick 2.0
import "../Components/OrderPages"
import "../"

Row{

    id: root
    property alias loader: orderLoader
    property alias weighScale: idWeightDetails

    WeighingScale{
        id: idWeightDetails
        width: parent.width * 0.4
        height: parent.height * 0.4

    }

    Loader {
        id: orderLoader
        width: parent.width * 0.4
        height: parent.height


    }

}

