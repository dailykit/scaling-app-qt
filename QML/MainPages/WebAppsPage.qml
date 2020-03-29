import QtQuick 2.0
import QtWebEngine 1.4
import QtQuick.Controls 2.5

WebEngineView {
    id: webView

    // Make sure focus is not taken by the web view, so user can continue navigating
    // recipes with the keyboard.
    settings.focusOnNavigationEnabled: false

    onContextMenuRequested: function(request) {
        request.accepted = true
    }

    property bool firstLoadComplete: false
    onLoadingChanged: function(loadRequest) {
        if (loadRequest.status === WebEngineView.LoadSucceededStatus
                && !firstLoadComplete) {
            // Debounce the showing of the web content, so images are more likely
            // to have loaded completely.
            showTimer.start()
        }
    }

    Timer {
        id: showTimer
        interval: 500
        repeat: false
        onTriggered: {
            webView.show(true)
            webView.firstLoadComplete = true
            recipeList.showHelp()
        }
    }

    Rectangle {
        id: webViewPlaceholder
        anchors.fill: parent
        z: 1
        color: "white"

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
}

