#ifndef MAINVIEWMODEL_H
#define MAINVIEWMODEL_H

#include <QObject>
#include "orderviewmodel.h"
#include "manipulateingredients.h"
#include "DailyKitCore/DatabaseModels/dbproxy.h"

class MainViewModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(ManipulateIngredients* manipulateIngredients READ manipulateIngredients NOTIFY manipulateIngredientsChanged)
public:
    explicit MainViewModel(QObject *parent = nullptr);

signals:
   void manipulateIngredientsChanged();

public slots:
    OrderViewModel *getOrdersModel();
    ManipulateIngredients* manipulateIngredients();

    Q_INVOKABLE void getOrders();

private:
    DbProxy *m_databaseProxy;
    OrderViewModel *m_orderModel;
    ManipulateIngredients *m_ingredientsManipulation;
};

#endif // MAINVIEWMODEL_H
