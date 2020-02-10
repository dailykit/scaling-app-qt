#include "ingredientviewmodel.h"
#include "../DatabaseModels/dbproxy.h"
#include "weighingscalemodel.h"

const QString IngredientViewModel::IngredientViewQuery ="SELECT  ingredients.ingredientId, ingredients.slipName FROM ingredients "
                                                        " WHERE ingredients.ingredientItemId = ?";

const QString IngredientViewModel::TAG ="IngredientViewModel.cpp : ";

IngredientViewModel::IngredientViewModel(QObject *parent)
    : QAbstractListModel(parent),
      m_orderNumber(0),
      dataPage(new RetrieveWebAppData)
{
    connect(DbProxy::dbInstance(), &DbProxy::ingredientPackedChanged, this, &IngredientViewModel::updateIngredientDetail);
    connect(DbProxy::dbInstance(), &DbProxy::ingredientDeleted, this, &IngredientViewModel::onIngredientDeleted);
}

IngredientViewModel::~IngredientViewModel()
{
    qDebug() <<TAG<<"deleted";
}

int IngredientViewModel::orderNumber() const
{
    return m_orderNumber;
}

void IngredientViewModel::setOrderNumber(int order)
{
    m_orderNumber = order;
    emit orderNumberChanged();
}

QString IngredientViewModel::itemName() const
{
    return m_itemName;
}

void IngredientViewModel::setItemName(QString item)
{
    m_itemName = item;
    emit itemNameChanged();
}

void IngredientViewModel::setQuery(const QString &itemId)
{
    qDebug() << "setQuery called "<< itemId;
    QSqlQuery query;

    beginResetModel();
    query.prepare(IngredientViewQuery);
    query.addBindValue(itemId);

    if (query.exec()) {

        m_ingredientsList.clear();
        m_detailsModel.clear();

        while (query.next()){

            IngredientsPtr ptr(new Ingredients());
            QSqlQuery query1;
            ptr->setIngredientId(query.value(0).toString());
            ptr->setIngredientName(query.value(1).toString());
            query1.prepare("SELECT ingredientDetails.ingredientDetailId, ingredientDetails.ingredientName, "
                           "ingredientDetails.ingredientQuantity, ingredientDetails.ingredientMsr, ingredientDetails.ingredientProcess, ingredientDetails.isPacked"
                           " FROM ingredientDetails WHERE ingredientDetails.ingredientId = ?");
            query1.addBindValue(ptr->ingredientId());
            if (query1.exec()) {

                QSharedPointer<IngredientDetailViewModel> model(new IngredientDetailViewModel());

                while (query1.next()){
                    IngredientDetailsPtr details(new IngredientDetails());
                    details->IngredientDetails::m_ingredientDetailId = query1.value(0).toString();
                    details->IngredientDetails::m_ingredientName = query1.value(1).toString();
                    details->IngredientDetails::m_ingredientQuantity = query1.value(2).toFloat();
                    details->IngredientDetails::m_ingredientMeasure = query1.value(3).toString();
                    details->IngredientDetails::m_ingredientProcess =  query1.value(4).toString();
                    details->IngredientDetails::m_isIngredientPacked = query1.value(5).toInt();
                    details->IngredientDetails::m_ingredientId = query.value(0).toString();
                    ptr->setIngredientDetail(details);
                    model->setIngredientDetails(details);
                }
                m_detailsModel.append(model);

            } else {
                qDebug() <<query1.lastError();
            }
            m_ingredientsList.append(ptr);
        }

    }
    else{
        qDebug() <<"Errors occured with sql statement" <<  query.executedQuery();
        qDebug() <<query.lastError();
    }

    endResetModel();

}

void IngredientViewModel::updateIngredientDetail(const QString &indgredientDetailsId)
{


    int isElementFound = 0;
    for(int i = 0; i < m_ingredientsList.count(); ++i) {
        if(isElementFound == 1 || isElementFound == 2) {
            selectNextIngredientToPack();
            break;
        }
        for(int j = 0; j < m_detailsModel[i]->ingredientList().count(); ++j)
        {
            if(isElementFound == 1) {
                break;
            }
            if(m_detailsModel[i]->ingredientList()[j]->IngredientDetails::m_ingredientDetailId == indgredientDetailsId) {
                m_detailsModel[i]->ingredientList()[j]->IngredientDetails::m_isIngredientPacked = 1;
                isElementFound = 1;

            }
        }
        if(m_ingredientsList[i]->ingredientDetails()->IngredientDetails::m_ingredientDetailId == indgredientDetailsId) {
            m_ingredientsList[i]->ingredientDetails()->IngredientDetails::m_isIngredientPacked = 1;
            QModelIndex model = createIndex(i, 0);

            emit dataChanged(model, model);
        }

    }
}

void IngredientViewModel::onIngredientDeleted(const QString ingredientId)
{
    for(int i = 0; i < m_ingredientsList.count(); ++i) {
        for(int j = 0; j < m_detailsModel[i]->ingredientList().count(); ++j)
        {
            if(m_detailsModel[i]->ingredientList()[j]->IngredientDetails::m_ingredientId == ingredientId) {
                m_detailsModel.removeAt(j);
            }
        }

        if(m_ingredientsList[i]->ingredientId() == ingredientId) {
            QModelIndex modelStart = createIndex(i, 0);
            beginRemoveRows(modelStart.parent(), modelStart.row(), modelStart.row());
            m_ingredientsList.removeAt(i);
            endRemoveRows();
        }
    }
}

void IngredientViewModel::selectNextIngredientToPack()
{
    int isElementFound = 0;
    for(int i = 0; i < m_ingredientsList.count(); ++i) {
        for(int j = 0; j < m_detailsModel[i]->ingredientList().count(); ++j)
        {
            if(m_detailsModel[i]->ingredientList()[j]->IngredientDetails::m_isIngredientPacked == 0) {
                WeighingScaleModel::weighScaleInstance()->weighItem(m_detailsModel[i]->ingredientList()[j]->IngredientDetails::m_ingredientDetailId,
                                                                    m_detailsModel[i]->ingredientList()[j]->IngredientDetails::m_ingredientName, m_detailsModel[i]->ingredientList()[j]->IngredientDetails::m_ingredientQuantity
                                                                    ,m_detailsModel[i]->ingredientList()[j]->IngredientDetails::m_ingredientMeasure);
                isElementFound = 1;

                emit itemIndexChanged(i);
                if(m_detailsModel.count() > 1)
                    emit ingredientIndexChanged(j);
                break;
            }
        }
        if(isElementFound == 1) {
            break;
        }
    }
}


QVariant IngredientViewModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= m_ingredientsList.count())
    {
        return QVariant();

    }

    switch (role) {
    case IngredientId:
        return m_ingredientsList[index.row()]->ingredientId();
    case IngredientSlipName:
        return m_ingredientsList[index.row()]->ingredientName();
    case IngredientDetailList:
        return QVariant::fromValue(m_detailsModel[index.row()]);
    case IngredientProcess:
        return m_ingredientsList[index.row()]->ingredientDetails()->IngredientDetails::m_ingredientProcess;
    case IngredientQuantity:
        return m_ingredientsList[index.row()]->ingredientDetails()->IngredientDetails::m_ingredientQuantity;
    case IngredientWeight:
        return m_ingredientsList[index.row()]->ingredientDetails()->IngredientDetails::m_ingredientMeasure;
    case IngredientPacked:
        return m_ingredientsList[index.row()]->ingredientDetails()->IngredientDetails::m_isIngredientPacked;
    case IngredientDetailId:
        return m_ingredientsList[index.row()]->ingredientDetails()->IngredientDetails::m_ingredientDetailId;
    case BackIcon:
        return QString::fromUtf8("\u3008");
    default:
        return QVariant();

    }
}

QHash<int, QByteArray> IngredientViewModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles.insert(IngredientId, "ingredientId");
    roles.insert(IngredientSlipName, "ingredientSlipName");
    roles.insert(IngredientDetailList, "ingredientList");
    roles.insert(IngredientProcess, "ingredientProcess");
    roles.insert(IngredientQuantity, "quantity");
    roles.insert(IngredientWeight, "ingredientWeight");
    roles.insert(IngredientPacked, "ingredientPacked");
    roles.insert(IngredientDetailId, "ingredientDetailId");
    roles.insert(BackIcon, "backIcon");
    return roles;
}

int IngredientViewModel::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid())
        return 0;

    return m_ingredientsList.count();
}

void IngredientViewModel::getIngredients(const QString ItemId)
{
    qDebug()<< "ingredient data fetching" << ItemId;
    setQuery(ItemId);
}
