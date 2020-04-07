import QtQuick 2.0
import "../ApplicationCore/Style"

ListModel {

    ListElement {
        name: "Order App"
        url: "MainOrdersPage.qml"
        isWebApp: false
        appColor: "#136f63"
    }

    ListElement {
        name: "Shop App"
        url: "https://rmk-dailykit.netlify.com/"
        isWebApp: true
        appColor: "#58355e"
    }

    ListElement {
        name: "Recipe App"
        url: "https://recipe-dailyos.netlify.com"
        isWebApp: true
        appColor: "#ffba08"
    }

    ListElement {
        name: "Settings App"
        url: "https://settings-app.netlify.com"
        isWebApp: true
        appColor:  "#fe4a49"
    }

    ListElement {
        name: "Revenue App"
        url: "http://roi.dailykit.org/"
        isWebApp: true
        appColor: "#3066be"
    }

    ListElement {
        name: "Seller App"
        url: "https://sellerapp.netlify.com/"
        isWebApp: true
        appColor: "#72195a"
    }
}

