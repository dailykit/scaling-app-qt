import QtQuick 2.0
import QtWebEngine 1.4
import QtQuick.Controls 2.5

WebEngineView {
    id: webView

    property string urlLink

    onContextMenuRequested: function(request) {
        request.accepted = true
    }

    property bool firstLoadComplete: false
    onLoadingChanged: function(loadRequest) {
        if (loadRequest.status === WebEngineView.LoadSucceededStatus
                ) {
            // Debounce the showing of the web content, so images are more likely
            // to have loaded completely.
          //  showTimer.start()
            webView.show(true)
        }
    }

    Timer {
        id: showTimer
        interval: 500
        repeat: false
        onTriggered: {
            webView.show(true)
            webView.firstLoadComplete = true
          //  recipeList.showHelp()
        }
    }

    Rectangle {
        id: webViewPlaceholder
        anchors.fill: parent
        z: 1
        color: "pink"

        BusyIndicator {
            id: busy
            anchors.centerIn: parent
        }
    }

    function showRecipe(url) {
        webView.url = url
    }

    function show(show) {
        if (show === true) {
            busy.running = false
            webViewPlaceholder.visible = false
        } else {
            webViewPlaceholder.visible = true
            busy.running = true
        }
    }
    Component.onCompleted: {
     console.log("urllink----------------", urlLink)
        showRecipe(urlLink)
    }
}

