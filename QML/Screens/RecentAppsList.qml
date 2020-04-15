import QtQuick 2.0

import "../Components/OrderPages"
import "../ComponentsCore/Views"
import "../ComponentsCore/Shapes"
import "../ApplicationCore/Style"

Item{
    id: root
    width: parent.width
    height: parent.height
    property alias list: recentList
    signal appClicked(url url)

    AppListView {
        id: recentList

        width: parent.width
        height: parent.height
        orientation: Qt.Horizontal
        spacing: 10
        model: mainModel.recentApps

        delegate: Rectangle {
            id: recentAppsDelegate
            height: 30
            width: 30
            color: model.appColor

            MouseArea{
                id: recentAppsMouseArea
                anchors.fill: parent
                onClicked: {
                    appClicked(model.url)
                }

            }
        }
    }
}
