#include "loginhandler.h"

LoginHandler::LoginHandler(QObject *parent) :
    QObject(parent),
    m_loginmanager(new LoginAccessManager)
{

    if(m_loginmanager != nullptr) {
        connect(m_loginmanager, &LoginAccessManager::loginResponseSucceeded, this, &LoginHandler::onLoginSuccessful);
        connect(m_loginmanager, &LoginAccessManager::loginResponseFailed,  this, &LoginHandler::onLoginFailed);
        connect(m_loginmanager, &LoginAccessManager::loggedOut,  this, &LoginHandler::onLoggedOut);
    }
}

LoginHandler::~LoginHandler()
{
    delete m_loginmanager;
}


/**
 * @brief LoginHandler::username - get the username to show on the Main page
 * @return - QString
 */
QString LoginHandler::userName() const
{
    return m_userName;
}


/**
 * @brief LoginHandler::setUserName - set the username for the application
 * @param name - QString
 */
void LoginHandler::setUserName(const QString name)
{
    m_userName = name;
    emit userNameChanged();
}


/**
 * @brief LoginHandler::sendLoginRequest - send login details to server to validate user
 * @param userName - QString
 * @param password - QString
 */
void LoginHandler::sendLoginRequest(const QString userName, const QString password)
{
    m_loginmanager->sendLoginDetails(userName, password);
    setUserName(userName);
}


/**
 * @brief LoginHandler::sendLogoutRequest - request for a logout from the session
 */
void LoginHandler::sendLogoutRequest()
{
    qDebug() << Q_FUNC_INFO;
    m_loginmanager->sendLogoutRequest();
}


/**
 * @brief LoginHandler::onLoginSuccessful - slot invoked when login successful response is received and
 * in return emits a signal to QML to open the mainpage
 */
void LoginHandler::onLoginSuccessful()
{
    qDebug() << Q_FUNC_INFO;
    emit loginSucessfullyCompleted();
}


/**
 * @brief LoginHandler::onLoginFailed - slot invoked when user login fails and in return emits signal to
 * ask user to enter correct data
 */
void LoginHandler::onLoginFailed()
{
    emit loginFailed();
}


/**
 * @brief LoginHandler::onLoggedOut - slot invoked when user logsout of the current session
 */
void LoginHandler::onLoggedOut()
{
    emit loggedOut();
}
