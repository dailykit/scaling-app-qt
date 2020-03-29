import QtQuick 2.0

Item {

    ListModel {
        id: appsModel

        ListElement {
            name: "Order App"
            url: "MainOrdersPage.qml"
            isWebApp: false
        }

        ListElement {
            name: "Shop App"
            url: "https://rmk-dailykit.netlify.com/"
            isWebApp: true
        }

        ListElement {
            name: "Recipe App"
            url: "https://recipe-dailyos.netlify.com"
            isWebApp: true
        }

        ListElement {
            name: "Settings App"
            url: "https://settings-app.netlify.com"
            isWebApp: true
        }

        ListElement {
            name: "Revenue App"
            url: "http://roi.dailykit.org/"
            isWebApp: true
        }

        ListElement {
            name: "Seller App"
            url: "https://sellerapp.netlify.com/"
            isWebApp: true
        }
    }
}
