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
    readonly property string profile: imagesPath + "profile.svg";
    readonly property string orderImage: imagesPath + "order_id.svg";
    readonly property string inventory: imagesPath + "inventory.svg";
    readonly property string planning: imagesPath + "planning.svg";
    readonly property string settings: imagesPath + "settings.svg";
    readonly property string printer: imagesPath + "print.svg";


}
