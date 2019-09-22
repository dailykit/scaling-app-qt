import QtQuick 2.0

import "../Components/OrderPages"
import "../ComponentsCore/Views"
import "../ApplicationCore/Style"

AppListView {
    id: trialRect

    model: ingredientModel
    delegate: IngredientSectionDelegate {
        id: delegateIngredient
        height: Interface.orderView.rowHeight + detailsList.height
        width: parent.width

    }

}
