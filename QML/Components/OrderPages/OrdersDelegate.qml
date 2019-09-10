import QtQuick 2.0
import "../../ApplicationCore/Style"
Item {
    id: root

    Rectangle{
        height: Interface.orderView.rowHeight
        width: Interface.orderView.rowWidth
        color: Themes.selectedTheme.appGrey

        Row {
            id: ingredientsRow

            height: Interface.orderView.rowHeight
            width: Interface.orderView.rowWidth
            spacing: Interface.orderView.ingredientRowSpacing


        }
    }

}
