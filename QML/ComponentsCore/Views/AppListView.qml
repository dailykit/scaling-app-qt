import QtQuick 2.0
import QtQuick.Controls 1.4


ListView{
    id: list;

    property string sectionProperty
    property Component sectionDelegate

//    anchors.fill: parent
    clip: true

    // two properties are used to create sections in the list view:
    // eg: Create sections based on order id
    section.property: sectionProperty
    section.delegate: sectionDelegate




}
