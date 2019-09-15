import QtQuick 2.0

import "../Components/OrderPages"
import "../ComponentsCore/Views"
import "../ApplicationCore/Style"

AppListView {
    id: trialRect


    model: ingredientModel
    delegate: IngredientsDelegate {
        id: delegateIngredient

        height: Interface.orderView.rowHeight
        width: parent.width


    }
    property int cou: delegateIngredient.index
    snapMode: ListView.SnapToItem

    sectionProperty: "ingredientSlipName"
    sectionDelegate: IngredientSectionDelegate{
        id: delegateSection

        height: Interface.orderView.rowHeight
        width: parent.width


    }


}
