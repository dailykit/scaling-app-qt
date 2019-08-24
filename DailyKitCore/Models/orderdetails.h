#ifndef ORDERDETAILS_H
#define ORDERDETAILS_H

#include <QObject>

class OrderDetails : public QObject
{
    Q_OBJECT
public:
    explicit OrderDetails(QObject *parent = nullptr);

signals:

public slots:
};

#endif // ORDERDETAILS_H
