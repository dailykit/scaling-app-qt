#include "loginaccessmanager.h"

const QString LoginAccessManager::LOGIN_URL = "http://ec2-18-191-54-7.us-east-2.compute.amazonaws.com:8080/auth/realms/realm80/protocol/openid-connect/token";
const QString LoginAccessManager::CONTENT_HEADER = "application/x-www-form-urlencoded";
/*
--header 'Content-Type: application/x-www-form-urlencoded'
--data-urlencode 'grant_type=password'
--data-urlencode 'client_id=device1'
--data-urlencode 'username=testuser'
--data-urlencode 'password=password'
--data-urlencode 'client_secret=1d200852-5567-46c8-b479-b63a714e11ee'
--data-urlencode 'scope=openid'
*/



LoginAccessManager::LoginAccessManager(QObject *parent) :
    QObject(parent),
    m_loginManager(new QNetworkAccessManager)
{

    if(m_loginManager)
    {
        connect(m_loginManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onDataReceived(QNetworkReply*)));
    }
}

void LoginAccessManager::sendLoginDetails(const QString userName, const QString password)
{
    QNetworkRequest request(LOGIN_URL);
    request.setHeader(QNetworkRequest::ContentTypeHeader, CONTENT_HEADER);

    QUrlQuery query;

    query.addQueryItem("grant_type","password");
    query.addQueryItem("client_id","device1");
    query.addQueryItem("username", userName);
    query.addQueryItem("password",password);
    query.addQueryItem("client_secret","1d200852-5567-46c8-b479-b63a714e11ee");
    query.addQueryItem("scope","openid");

    QByteArray postData;
    postData = query.toString(QUrl::FullyEncoded).toUtf8();

    if(m_loginManager) {
        m_loginManager->post(request, postData);
    }
    else
    {
        qWarning() << "Null pointer";
    }

}

void LoginAccessManager::onDataReceived(QNetworkReply *loggedinData)
{

    switch (loggedinData->error()) {
    case QNetworkReply::AuthenticationRequiredError:
        emit loginResponseFailed();
        break;
    case QNetworkReply::NoError:
        qDebug() << "success";

        QByteArray byteArray = loggedinData->readAll();

        QJsonParseError error;
        QJsonDocument jsonDocument = QJsonDocument::fromJson(byteArray, &error);

        QJsonObject jsonObject = jsonDocument.object();

        qDebug() << "json object details" << jsonObject.value("access_token").toString() << "\n"
                 << jsonObject.value("expires_in").toInt();

        emit loginResponseSucceeded();
        break;

    }

}
