#ifndef LOGINHANDLER_H
#define LOGINHANDLER_H

#include <QObject>
#include "DailyKitCore/External/WebServices/loginaccessmanager.h"

class LoginHandler : public QObject
{
    Q_OBJECT
public:
    explicit LoginHandler(QObject *parent = nullptr);
    ~LoginHandler();

signals:
    void loginSucessfullyCompleted();
    void loginFailed();

public slots:
   Q_INVOKABLE void sendLoginRequest(const QString userName, const QString password);
    void onLoginSuccessful();
    void onLoginFailed();

private:
    LoginAccessManager *m_loginmanager;
};

#endif // LOGINHANDLER_H
