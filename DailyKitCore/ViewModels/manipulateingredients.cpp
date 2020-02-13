#include "manipulateingredients.h"
#include "DailyKitCore/DatabaseModels/dbproxy.h"
#include <QDebug>

ManipulateIngredients::ManipulateIngredients(QObject *parent) : QObject(parent)
{
    connect(DbProxy::dbInstance(), &DbProxy::ingredientWeighedChanged, this, &ManipulateIngredients::setAsIngredientPacked);
}

ManipulateIngredients::~ManipulateIngredients()
{
}

void ManipulateIngredients::deleteIngredient(const QString ingredientId)
{
    qDebug() << "Delete Ingredient";
    DbProxy::dbInstance()->deleteIngredient(ingredientId);
}

void ManipulateIngredients::setAsIngredientPacked(const QString ingredientDetailId)
{
    qDebug() << Q_FUNC_INFO << ingredientDetailId;
    DbProxy::dbInstance()->setIngredientAsPackedCompleted(ingredientDetailId);
}
