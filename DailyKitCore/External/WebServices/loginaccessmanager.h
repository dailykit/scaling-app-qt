/**************************************************************************
LoginAccessManger is responsible to get send login details through Network
and get the token for accessing the application; the login is accessed through
KeyCloak which on sending the login details will send the login token and session
time
**************************************************************************/



#ifndef LOGINACCESSMANAGER_H
#define LOGINACCESSMANAGER_H

#include <QNetworkAccessManager>
#include <QtNetwork>
#include <QObject>

struct LoginDetails {
    QString userName;
    QString password;
};

class LoginAccessManager : public QObject
{
    Q_OBJECT

    enum REQUEST_TYPE {
        LOGIN,
        LOGOUT,
        REFRESH,
        NONE
    };

public:
    explicit LoginAccessManager(QObject *parent = nullptr);

    void sendLoginDetails(const QString userName, const QString password);
    void sendLogoutRequest();

signals:
    void loginResponseSucceeded();
    void loginResponseFailed();
    void loggedOut();

private slots:
     void onDataReceived(QNetworkReply* loggedinData);


private:
     QNetworkAccessManager *m_loginManager;
     static const QString LOGIN_URL;
     static const QString CONTENT_HEADER;

     static const QString LOGOUT_URL;
     static const QString REFRESH_TOKEN_URL;


     QString m_accessToken;
     QString m_refreshToken;

     REQUEST_TYPE m_requestType;

};

#endif // LOGINACCESSMANAGER_H
