#ifndef MANIPULATEINGREDIENTS_H
#define MANIPULATEINGREDIENTS_H

#include <QObject>

class ManipulateIngredients : public QObject
{
    Q_OBJECT
public:
    explicit ManipulateIngredients(QObject *parent = nullptr);
    ~ManipulateIngredients();



public slots:
    Q_INVOKABLE void deleteIngredient(const QString ingredientId);

private:
    void setAsIngredientPacked(const QString ingredientDetailId);

};

#endif // MANIPULATEINGREDIENTS_H
