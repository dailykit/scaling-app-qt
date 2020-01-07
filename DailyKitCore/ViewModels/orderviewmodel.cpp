#include "orderviewmodel.h"


const QString OrderViewModel::OrderViewQuery = "SELECT  itemDetails.itemOrderId, itemDetails.orderId, itemDetails.itemName, itemDetails.itemServing"
                                               ", (SELECT Count(I1.ingredientId) FROM ingredients I1 WHERE I1.ingredientItemId = itemDetails.itemOrderId) as counttotal"
                                               ", (SELECT SUM(I2.isPackedComplete) FROM ingredients I2 WHERE I2.ingredientItemId = itemDetails.itemOrderId) as turnover "
                                               ", (SELECT orderNumber FROM orderDetails where orderDetails.orderId = itemDetails.orderId) FROM itemDetails";



OrderViewModel::OrderViewModel(QObject *parent) :
    QAbstractListModel(parent),
    m_recordCount(0)

{   
}


OrderViewModel::~OrderViewModel()
{
    qDebug() << "deleted";
}

int OrderViewModel::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid())
        return 0;

    return m_itemDetails.count();

}

void OrderViewModel::onOrderDetailsReceived(QList<ItemDetailsPtr> itemDetails)
{
    beginResetModel();
            m_itemDetails = itemDetails;
   endResetModel();

}



QHash<int, QByteArray> OrderViewModel::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles.insert(ItemOrderId, "itemOrderId");
    roles.insert(OrderId, "orderId");
    roles.insert(ItemName, "itemName");
    roles.insert(ItemServing, "itemServing");
    roles.insert(IngredientCount, "ingredientCount");
    roles.insert(PackedIngredientCount, "packedCount");
    roles.insert(OrderNumber, "orderNumber");

    return roles;
}

QVariant OrderViewModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= m_itemDetails.count())
    {
        return QVariant();

    }

    switch (role) {
    case ItemOrderId:
        return m_itemDetails[index.row()]->itemOrderId();
    case OrderId:
        return m_itemDetails[index.row()]->orderId();
    case ItemName:
        return m_itemDetails[index.row()]->recipeName();
    case ItemServing:
        return m_itemDetails[index.row()]->recipeServings();
    case IngredientCount:
        return m_itemDetails[index.row()]->ingredientCount();
    case PackedIngredientCount:
        return m_itemDetails[index.row()]->packedIngredients();
    case OrderNumber:
        return m_itemDetails[index.row()]->orderNumber();
    default:
        return QVariant();

    }
}
