#include "loginaccessmanager.h"

const QString LoginAccessManager::LOGIN_URL = "http://ec2-18-191-54-7.us-east-2.compute.amazonaws.com:8080/auth/realms/realm80/protocol/openid-connect/token";
const QString LoginAccessManager::CONTENT_HEADER = "application/x-www-form-urlencoded";

const QString LoginAccessManager::LOGOUT_URL = "http://ec2-18-191-54-7.us-east-2.compute.amazonaws.com:8080/auth/realms/realm80/protocol/openid-connect/logout";
const QString LoginAccessManager::REFRESH_TOKEN_URL = "http://ec2-18-191-54-7.us-east-2.compute.amazonaws.com:8080/auth/realms/realm80/protocol/openid-connect/token";

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
    m_loginManager(new QNetworkAccessManager),
    m_requestType(NONE)
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
        m_requestType = LOGIN;
    }
    else
    {
        qWarning() << "Null pointer";
    }

}


/**
 * @brief LoginAccessManager::sendLogoutRequest - handle the logout request for the particular session
 */
void LoginAccessManager::sendLogoutRequest()
{

    QString bearerArray = "Bearer " + m_accessToken;
//    qDebug() << arr;
    QByteArray bearer = bearerArray.toUtf8();
    //qDebug() << bearer;

    QNetworkRequest request(LOGOUT_URL);
    request.setHeader(QNetworkRequest::ContentTypeHeader, CONTENT_HEADER);
    request.setRawHeader(QByteArray("Authorization"), bearer);

    QUrlQuery query;

    query.addQueryItem("client_id", "device1");
    query.addQueryItem("refresh_token", m_refreshToken);
    query.addQueryItem("client_secret","1d200852-5567-46c8-b479-b63a714e11ee");

    QByteArray postData;
    postData = query.toString(QUrl::FullyEncoded).toUtf8();

    if(m_loginManager) {
        qDebug() << "logout request" << request.rawHeader("Authorization");
        m_loginManager->post(request, postData);

        m_requestType = LOGOUT;
    }
    else
    {
        qWarning() << "Null pointer";
    }
}

void LoginAccessManager::onDataReceived(QNetworkReply *loggedinData)
{
    qDebug() << "data received" << loggedinData->error() << loggedinData->url();

    switch (loggedinData->error()) {
    case QNetworkReply::AuthenticationRequiredError:

        switch (m_requestType) {
        case LOGIN:
            emit loginResponseFailed();
            break;
        case REFRESH:
        case NONE:
        default:
            break;
        }
        break;
    case QNetworkReply::NoError:
        qDebug() << "success";

        QByteArray byteArray = loggedinData->readAll();
        QJsonParseError error;
        QJsonDocument jsonDocument = QJsonDocument::fromJson(byteArray, &error);

        QJsonObject jsonObject = jsonDocument.object();
        switch (m_requestType) {

        case LOGIN:

            m_accessToken = jsonObject.value("access_token").toString();
            m_refreshToken = jsonObject.value("refresh_token").toString();

            emit loginResponseSucceeded();
            break;

        case LOGOUT:
            qDebug() << "logout emitted";
            emit loggedOut();
            break;

        case REFRESH:
        case NONE:
        default:
            break;
        }


        break;


    }

}
