#ifndef ORDERVIEWMODEL_H
#define ORDERVIEWMODEL_H

#include <QAbstractItemModel>

class OrderViewModel : public QAbstractItemModel
{
public:
    OrderViewModel( QObject *parent);
};

#endif // ORDERVIEWMODEL_H
