#include "manipulateingredients.h"
#include "DailyKitCore/DatabaseModels/dbproxy.h"
#include <QDebug>

ManipulateIngredients::ManipulateIngredients(QObject *parent) : QObject(parent)
{

}

ManipulateIngredients::~ManipulateIngredients()
{
}

void ManipulateIngredients::deleteIngredient(const QString ingredientId)
{
    qDebug() << "Delete Ingredient";
    DbProxy::dbInstance()->deleteIngredient(ingredientId);
}
