pragma Singleton
import QtQuick 2.0

QtObject{
    id: root

    readonly property string imagesPath: "qrc:/QML/Default/"
    readonly property string background: imagesPath + "background.jpg";
    readonly property string logo: imagesPath + "logo.svg";
    readonly property string orderNumber: imagesPath + "ic_order_number.png";
    readonly property string orderTime: imagesPath + "ic_order_time.png";
    readonly property string weight: imagesPath + "weight.png";
   // readonly property string profile: imagesPath + "profile.svg";
    readonly property string orderImage: imagesPath + "order_id.svg";
   // readonly property string inventory: imagesPath + "inventory.svg";
   // readonly property string planning: imagesPath + "planning.svg";
   // readonly property string settings: imagesPath + "settings.svg";
    readonly property string printer: imagesPath + "print.svg";

    readonly property string tear: "\ue900"
    readonly property string rightArrow: "\ue901"
    readonly property string leftArrow: "\ue902"
    readonly property string menu: "\ue903"
    readonly property string timer: "\ue904"
    readonly property string profile: "\ue905"
    readonly property string inventory: "\ue906"
    readonly property string planning: "\ue907"
    readonly property string serving: "\ue908"
    readonly property string weigh: "\ue909"
    readonly property string label: "\ue90a"
    readonly property string repack: "\ue90b"
    readonly property string close: "\ue90c"
    readonly property string order: "\ue90d"
    readonly property string realTime: "\ue90e"
    readonly property string settings: "\ue90f"

    readonly property FontLoader iconfont: FontLoader {
        id: icons
        source: "qrc:/QML/Default/fonts/icomoon.ttf"
    }

}
