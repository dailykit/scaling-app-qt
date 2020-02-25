#ifndef LOGINHANDLER_H
#define LOGINHANDLER_H

#include <QObject>
#include "DailyKitCore/External/WebServices/loginaccessmanager.h"

class LoginHandler : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString userName READ userName WRITE setUserName NOTIFY userNameChanged)
public:
    explicit LoginHandler(QObject *parent = nullptr);
    ~LoginHandler();

    QString userName() const;
    void setUserName(const QString name);

signals:
    void loginSucessfullyCompleted();
    void loginFailed();
    void userNameChanged();
    void loggedOut();

public slots:
    Q_INVOKABLE void sendLoginRequest(const QString userName, const QString password);
    Q_INVOKABLE void sendLogoutRequest();
    void onLoginSuccessful();
    void onLoginFailed();
    void onLoggedOut();

private:
    LoginAccessManager *m_loginmanager;
    QString m_userName;
};

#endif // LOGINHANDLER_H
