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

public:
    explicit LoginAccessManager(QObject *parent = nullptr);

    void sendLoginDetails(const QString userName, const QString password);

signals:
    void loginResponseSucceeded();
    void loginResponseFailed();

private slots:
     void onDataReceived(QNetworkReply* loggedinData);


private:
     QNetworkAccessManager *m_loginManager;
     static const QString LOGIN_URL;
     static const QString CONTENT_HEADER;

};

#endif // LOGINACCESSMANAGER_H
