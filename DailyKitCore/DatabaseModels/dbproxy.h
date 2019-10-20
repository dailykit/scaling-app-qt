#ifndef DBPROXY_H
#define DBPROXY_H

#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>
#include <QObject>

class DbProxy : public QObject
{
    Q_OBJECT

signals:
    void ingredientPackedChanged(const QString &ingredientDetailId);

public:

    void setIngredientAsPacked(const QString &ingredientId);
    void openDatabase();

    static DbProxy *dbInstance();

private:
    static const QString UPDATEINGREDIENTPACKED ;
    DbProxy(QObject *parent = nullptr);

    QString m_ingredientDetailUpdated;
   static DbProxy *m_databaseProxy;

};

#endif // DBPROXY_H
