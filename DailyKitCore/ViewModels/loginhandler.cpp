#include "loginhandler.h"

LoginHandler::LoginHandler(QObject *parent) :
    QObject(parent),
    m_loginmanager(new LoginAccessManager)
{

    if(m_loginmanager != nullptr) {
        connect(m_loginmanager, &LoginAccessManager::loginResponseSucceeded, this, &LoginHandler::onLoginSuccessful);
        connect(m_loginmanager, &LoginAccessManager::loginResponseFailed,  this, &LoginHandler::onLoginFailed);
    }
}

LoginHandler::~LoginHandler()
{
    delete m_loginmanager;
}


/**
 * @brief LoginHandler::sendLoginRequest - send login details to server to validate user
 * @param userName - QString
 * @param password - QString
 */
void LoginHandler::sendLoginRequest(const QString userName, const QString password)
{
    m_loginmanager->sendLoginDetails(userName, password);
}

void LoginHandler::onLoginSuccessful()
{
    emit loginSucessfullyCompleted();
}

void LoginHandler::onLoginFailed()
{
    emit loginFailed();
}
