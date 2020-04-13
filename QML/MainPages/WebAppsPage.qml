import QtQuick 2.0
import QtWebEngine 1.4
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.0

Item {
    id: root
    property string urlLink

    Column {
        height: parent.height
        width: parent.width
        spacing: 20

        TopBar {
            id: topBar

            height: parent.width * 0.029
            width: parent.width
        }


        WebEngineView {
            id: webView
            height: 600
            width: parent.width


            onContextMenuRequested: function(request) {
                request.accepted = true
            }


            onLoadingChanged: function(loadRequest) {
                if (loadRequest.status === WebEngineView.LoadSucceededStatus
                        ) {
                    // Debounce the showing of the web content, so images are more likely
                    // to have loaded completely.
                    //  showTimer.start()
                    console.log("loadinggg")
                    webView.show(true)
                }
            }

            Rectangle {
                id: webViewPlaceholder
                width: parent.width
                height: parent.height
                z: 1
                color: "white"

//                BusyIndicator {
//                    id: busy
//                    anchors.centerIn: parent
//                }
            }
            Component.objectName: {
                 webView.url = urlLink
            }

            function showRecipe(url) {
                webView.url = url
            }

            function show(show) {
                if (show === true) {
             //       busy.running = false
                    webViewPlaceholder.visible = false
                } else {
                    webViewPlaceholder.visible = true
               //     busy.running = true
                }
            }
        }
    }
}
