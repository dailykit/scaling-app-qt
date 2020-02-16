#include "retrievewebappdata.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDriver>

const QString RetrieveWebAppData::WEB_APP_URL = "http://ec2-18-188-115-230.us-east-2.compute.amazonaws.com:3000/getData";
const QString RetrieveWebAppData::CONTENT_HEADER ="application/json";
const QString RetrieveWebAppData::TAG ="retrievewebappdata.cpp : ";

RetrieveWebAppData::RetrieveWebAppData(QObject *parent) : QObject(parent)
  ,m_AccessManager(new QNetworkAccessManager)
{
    if(m_AccessManager)
    {
        connect(m_AccessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onDataReceived(QNetworkReply*)));
    }

}

void RetrieveWebAppData::getOrderList()
{
    QNetworkRequest request(WEB_APP_URL);
    request.setHeader(QNetworkRequest::ContentTypeHeader, CONTENT_HEADER);
    QByteArray response_data;
    if(m_AccessManager) {
        m_AccessManager->post(request, response_data);
    }
    else
    {
        qWarning() << "Null pointer";
    }
}

void RetrieveWebAppData::onDataReceived(QNetworkReply *orderData)
{
    qDebug();
    if (orderData->error() != QNetworkReply::NoError)
    {
        qDebug() << "Got some error " <<orderData->error();
    }
    else
    {
        qDebug() << "success";
        QByteArray byteArray = orderData->readAll();
        //ui->textEdit->setPlainText(byteArray);
        QJsonParseError error;
        QJsonDocument jsonDocument = QJsonDocument::fromJson(byteArray, &error);

        //qDebug() << "Is Object? " << jsonDocument.isObject();
        //qDebug() << "Is Array? " << jsonDocument.isArray();

        QJsonObject jsonObject = jsonDocument.object();

        // catch this data in model and manipulate the data there
        QJsonValue agentsArrayValue = jsonObject.value("all_orders");
        QJsonArray agentsArray = agentsArrayValue.toArray();


        foreach (const QJsonValue & v, agentsArray)
        {

           QSqlQuery query;
            query.prepare("INSERT OR IGNORE INTO orderDetails(orderId, orderNumber) "
                          "VALUES (?, ?)");


            query.addBindValue(v.toObject().value("order_id").toString());
            query.addBindValue(v.toObject().value("order_number").toInt());

            if(!query.exec()){

                qFatal("Failed to query database: %s", qPrintable(query.lastError().text()));
            }


            int index = 0;
            QJsonArray itemsArray = v.toObject().value("items").toArray();
            foreach (const QJsonValue & item, itemsArray)
            {

                QSqlQuery query;
                //                query.prepare("INSERT INTO itemDetails(itemOrderId, orderId, itemSku, itemName, itemStatus) "
                //                              "VALUES (:itemOrderId, :orderId, :itemSku, :itemName, :itemStatus)"
                //                              " ON DUPLICATE KEY UPDATE, itemSku = :itemSku,"
                //                             "itemName = :itemName, itemStatus = :itemStatus");

                //                query.prepare("UPDATE itemDetails SET ")



                query.prepare("INSERT OR IGNORE INTO itemDetails(itemOrderId, orderId, itemSku, itemName, itemServing ,itemStatus) "
                              "VALUES (?, ?, ?, ?, ?, ?)");

                query.addBindValue(item.toObject().value("item_order_id").toString());
                query.addBindValue(item.toObject().value("order_id").toString());
                query.addBindValue(item.toObject().value("recipe_sku").toString());
                query.addBindValue(item.toObject().value("recipe_name").toString());
                query.addBindValue(item.toObject().value("recipe_servings").toString().at(index));
                //query.bindValue(":itemQuantity", item.toObject().value("recipe_quantity").toString());
                query.addBindValue( item.toObject().value("order_status").toString());
                if(!query.exec()){

                    qFatal("Failed to query database: %s", qPrintable(query.lastError().text()));
                }

                index = index + 3;

                QJsonArray ingredientsArray = item.toObject().value("ingredients").toArray();
                foreach (const QJsonValue & ingredients, ingredientsArray)
                {
                    //qDebug()<<TAG<<"ingredients";
                    query.prepare("INSERT OR IGNORE INTO ingredients(ingredientId, ingredientItemId, ingredientIndex, slipName, isPackedComplete, isDeleted,  isLabeled, isScanned,  selectedIngredientPosition,  ingredientMeasuredTotalWeight) "
                                  "VALUES (:ingredientId, :ingredientItemId, :ingredientIndex, :slipName, :isPackedComplete, :isDeleted,  :isLabeled, :isScanned,  :selectedIngredientPosition,  :ingredientMeasuredTotalWeight)");
                    query.bindValue(":ingredientId", ingredients.toObject().value("ingredient_id").toString());
                    query.bindValue(":ingredientItemId", ingredients.toObject().value("item_id").toString());
                    query.bindValue(":ingredientIndex", ingredients.toObject().value("ingredient_index").toInt());
                    query.bindValue(":slipName", ingredients.toObject().value("slip_name").toString());
                    query.bindValue(":isPackedComplete", ingredients.toObject().value("ingredient_is_packed_complete").toInt());
                    query.bindValue(":isDeleted", ingredients.toObject().value("ingredient_is_deleted").toInt());
                    query.bindValue(":isLabeled", ingredients.toObject().value("ingredient_is_labeled").toInt());
                    query.bindValue(":isScanned", ingredients.toObject().value("ingredient_is_scanned").toInt());
                    query.bindValue(":selectedIngredientPosition", ingredients.toObject().value("selected_ingredient_position").toInt());
                    query.bindValue(":ingredientMeasuredTotalWeight", ingredients.toObject().value("ingredient_measured_total_weight").toString());
                    if(!query.exec()){

                        qFatal("Failed to query database: %s", qPrintable(query.lastError().text()));
                    }

                    QJsonArray ingredientsDetailArray = ingredients.toObject().value("ingredient_details").toArray();
                    foreach (const QJsonValue & ingredientDetail, ingredientsDetailArray)
                    {
                        //qDebug()<<TAG<<"ingredients_details";
                        //qDebug()<<TAG<<ingredientDetail.toObject().value("ingredient_name").toString();

                        query.prepare("INSERT OR IGNORE INTO ingredientDetails(ingredientDetailId, ingredientId, ingredientName, ingredientQuantity, ingredientMsr, ingredientSection,  ingredientProcess, isPacked,  ingredientPackTimestamp,  isDeleted,  isWeighed,  ingredientDetailIndex,  ingredientDetailPosition,  ingredientMeasuredWeight) "
                                      "VALUES (:ingredientDetailId, :ingredientId, :ingredientName, :ingredientQuantity, :ingredientMsr, :ingredientSection,  :ingredientProcess, :isPacked,  :ingredientPackTimestamp,  :isDeleted,  :isWeighed,  :ingredientDetailIndex,  :ingredientDetailPosition,  :ingredientMeasuredWeight)");
                        query.bindValue(":ingredientDetailId", ingredientDetail.toObject().value("ingredient_detail_id").toString());
                        query.bindValue(":ingredientId", ingredientDetail.toObject().value("ingredient_id").toString());
                        query.bindValue(":ingredientName", ingredientDetail.toObject().value("ingredient_name").toString());
                        query.bindValue(":ingredientQuantity", ingredientDetail.toObject().value("ingredient_quantity").toString());
                        query.bindValue(":ingredientMsr", ingredientDetail.toObject().value("ingredient_measure").toString());
                        query.bindValue(":ingredientSection", ingredientDetail.toObject().value("ingredient_section").toString());
                        query.bindValue(":ingredientProcess", ingredientDetail.toObject().value("ingredient_process").toString());
                        query.bindValue(":isPacked", ingredientDetail.toObject().value("ingredient_is_packed").toInt());
                        query.bindValue(":ingredientPackTimestamp", ingredientDetail.toObject().value("ingredient_pack_timestamp").toString());
                        query.bindValue(":isDeleted", ingredientDetail.toObject().value("ingredient_is_deleted").toInt());
                        query.bindValue(":isWeighed", ingredientDetail.toObject().value("ingredient_is_weighed").toInt());
                        query.bindValue(":ingredientDetailIndex", ingredientDetail.toObject().value("ingredient_detail_index").toInt());
                        query.bindValue(":ingredientDetailPosition", ingredientDetail.toObject().value("ingredient_detail_position").toInt());
                        query.bindValue(":ingredientMeasuredWeight", ingredientDetail.toObject().value("ingredient_measured_weight").toDouble());
                        if(!query.exec()){

                            qFatal("Failed to query database: %s", qPrintable(query.lastError().text()));
                        }
                    }
                }
            }
        }
        emit webDataChanged();
    }
}
