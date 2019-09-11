pragma Singleton
import QtQuick 2.0

QtObject{
    id: root

    readonly property string imagesPath: "qrc:/QML/Default/"
    readonly property string background: imagesPath + "background.jpg";
    readonly property string logo: imagesPath + "dailykit.png";
    readonly property string orderNumber: imagesPath + "ic_order_number.png";
    readonly property string orderTime: imagesPath + "ic_order_time.png";
    readonly property string weight: imagesPath + "weight.png";
    readonly property string userIcon: String.fromCharCode("\u1F464")
}
