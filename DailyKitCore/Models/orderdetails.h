/****************************************************************
 * OrderDetails class is responsible to manipulate the webdata received
 * and add and send data to respective classes
 * *************************************************************/

#ifndef ORDERDETAILS_H
#define ORDERDETAILS_H

#include <QObject>

#include "../External/WebServices/retrievewebappdata.h"

class OrderDetails : public QObject
{
    Q_OBJECT
public:
    explicit OrderDetails(QObject *parent = nullptr);

signals:

public slots:
    void onWebDataChanged(QJsonObject &data);
};

#endif // ORDERDETAILS_H
