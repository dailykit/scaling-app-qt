#ifndef RETRIEVEWEBAPPDATA_H
#define RETRIEVEWEBAPPDATA_H

#include <QNetworkAccessManager>
#include <QtNetwork>
#include <QObject>

class RetrieveWebAppData : public QObject
{
    Q_OBJECT

public:
    RetrieveWebAppData(QObject *parent = nullptr);
    void getOrderList();

public slots:

   void onDataReceived(QNetworkReply* orderData);

signals:
  void webDataChanged(QJsonObject& webData);

private:
   QNetworkAccessManager *m_AccessManager;
   static const QString WEB_APP_URL;
   static const QString CONTENT_HEADER;

};

#endif // RETRIEVEWEBAPPDATA_H
