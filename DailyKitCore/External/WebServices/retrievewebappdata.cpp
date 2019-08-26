#include "retrievewebappdata.h"


const QString RetrieveWebAppData::WEB_APP_URL = "http://ec2-18-188-115-230.us-east-2.compute.amazonaws.com:3000/getData";
const QString RetrieveWebAppData::CONTENT_HEADER ="application/json";


RetrieveWebAppData::RetrieveWebAppData(QObject *parent) :
    QObject(parent),
    m_AccessManager(new QNetworkAccessManager)
{
    if(m_AccessManager) {
        connect(m_AccessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onDataReceived(QNetworkReply*)));
    }
    getOrderList();

}

void RetrieveWebAppData::getOrderList()
{
    QNetworkRequest request(WEB_APP_URL);
    request.setHeader(QNetworkRequest::ContentTypeHeader, CONTENT_HEADER);
    QByteArray response_data;

    if(m_AccessManager) {
        m_AccessManager->post(request, response_data);
    } else {
        qWarning() << "Null pointer";
    }
}

void RetrieveWebAppData::onDataReceived(QNetworkReply *orderData)
{
    qDebug();
    if (orderData->error() != QNetworkReply::NoError) {
       qDebug() << "Got some error " <<orderData->error();

    }else {
qDebug() << "success";

QByteArray byteArray = orderData->readAll();
        //ui->textEdit->setPlainText(byteArray);

        QJsonParseError error;
        QJsonDocument jsonDocument = QJsonDocument::fromJson(byteArray, &error);

        qDebug() << "Is Object? " << jsonDocument.isObject();
        qDebug() << "Is Array? " << jsonDocument.isArray();

        QJsonObject jsonObject = jsonDocument.object();

        emit webDataChanged(jsonObject); // catch this data in model and manipulate the data there
        QJsonValue agentsArrayValue = jsonObject.value("all_orders");
            QJsonArray agentsArray = agentsArrayValue.toArray();

            foreach (const QJsonValue & v, agentsArray)
            {
                qDebug() << v.toObject().value("order_id").toString();
                qDebug() << v.toObject().value("order_number").toInt();
                QJsonArray itemsArray = v.toObject().value("items").toArray();
                foreach (const QJsonValue & item, itemsArray)
                {
                    qDebug() << "items inside order";
                   qDebug() << item.toObject().value("item_order_id").toString();
                   qDebug() << item.toObject().value("order_status").toString();

                   QJsonArray ingredientsArray = item.toObject().value("ingredients").toArray();
                   foreach (const QJsonValue & ingredients, ingredientsArray)
                   {
                       qDebug() << "ingredients";
                       qDebug() << ingredients.toObject().value("slip_name").toString();

                   }

                }



                qDebug() << "--------------------";
            }
            }


}
