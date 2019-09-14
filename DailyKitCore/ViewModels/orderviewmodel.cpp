#include "orderviewmodel.h"


const QString OrderViewModel::OrderViewQuery = "SELECT  itemDetails.itemOrderId, itemDetails.orderId, itemDetails.itemName, itemDetails.itemServing"
                                               ", (SELECT Count(I1.ingredientId) FROM ingredients I1 WHERE I1.ingredientItemId = itemDetails.itemOrderId) as counttotal"
                                              ", (SELECT SUM(I2.isPackedComplete) FROM ingredients I2 WHERE I2.ingredientItemId = itemDetails.itemOrderId) as turnover FROM itemDetails";


OrderViewModel::OrderViewModel(QObject *parent) :
    QAbstractListModel(parent),
    m_recordCount(0),
    dataPage(new RetrieveWebAppData)
{

    if(dataPage) {
        dataPage->getOrderList();
        connect(dataPage, &RetrieveWebAppData::webDataChanged, this, &OrderViewModel::setQuery);
    }
    setQuery();
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

void OrderViewModel::setQuery()
{
    QSqlQuery query;

    if(query.exec(OrderViewQuery)) {
        qDebug()<<"sql statement exicuted fine";
    }
    else{
        qDebug() <<"Errors accured with sql statement";
        qDebug() <<query.lastError();
    }

    m_itemDetails.clear();
    beginResetModel();
    while (query.next()){

        ItemDetailsPtr ptr(new ItemDetails());
        ptr->setItemOrderId(query.value(0).toString());
        ptr->setOrderId(query.value(1).toString());
        ptr->setRecipeName(query.value(2).toString());
        ptr->setRecipeServings(query.value(3).toString());
        ptr->setIngredientCount(query.value(4).toInt());
        ptr->setPackedIngredients(query.value(5).toInt());

        m_itemDetails.append(ptr);

    }
    endResetModel();
}


QHash<int, QByteArray> OrderViewModel::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles.insert(ItemOrderId, "itemOrderId");
    roles.insert(OrderId, "orderId");
    roles.insert(ItemName, "itemName");
    roles.insert(ItemServing, "itemServing");
    roles.insert(UserIcon, "userIcon");
    roles.insert(RightArrow, "arrow");
    roles.insert(IngredientCount, "ingredientCount");
    roles.insert(PackedIngredientCount, "packedCount");

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
    case UserIcon:
        return QString::fromUtf8("\u1F464");
    case RightArrow:
        return QString::fromUtf8("\u3009");
    case IngredientCount:
        return m_itemDetails[index.row()]->ingredientCount();
    case PackedIngredientCount:
        return m_itemDetails[index.row()]->packedIngredients();
    default:
        return QVariant();

    }
}
