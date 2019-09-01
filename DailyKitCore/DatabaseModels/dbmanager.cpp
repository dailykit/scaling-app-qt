#include "dbmanager.h"

const QString DBManager::DRIVER = "QSQLITE";
const QString DBManager::ORDERTABLE = "orderDetails";
const QString DBManager::ITEMSTABLE = "itemDetails";

DBManager::DBManager()
{

}

DBManager::~DBManager()
{

}

void DBManager::connectToDatabase()
{
    qDebug() << "Connecting to database";
    QSqlDatabase database = QSqlDatabase::database();
    if (!database.isValid()) {
        database = QSqlDatabase::addDatabase(DRIVER);
        if (!database.isValid())
            qFatal("Cannot add database: %s", qPrintable(database.lastError().text()));
    }

    const QDir writeDir = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    qDebug() << writeDir.absolutePath();
    if (!writeDir.mkpath("."))
        qFatal("Failed to create writable directory at %s", qPrintable(writeDir.absolutePath()));

    // Ensure that we have a writable location on all devices.
    const QString fileName = writeDir.absolutePath() + "dailyKit-database.db";
    // When using the SQLite driver, open() will create the SQLite database if it doesn't exist.
    database.setDatabaseName(fileName);
    if (!database.open()) {
        qFatal("Cannot open database: %s", qPrintable(database.lastError().text()));
    } else {
        qDebug() <<"DB created";
        createOrderTable();
        createItemTable();
    }
}


void DBManager::createOrderTable()
{
    if (QSqlDatabase::database().tables().contains(ORDERTABLE)) {
        // The table already exists; we don't need to do anything.
        qDebug() << "table exists";
        return;
    }

    QSqlQuery query;
    if (!query.exec(
        "CREATE TABLE IF NOT EXISTS 'orderDetails' ("
        "'orderId' TEXT NOT NULL"
        ")")) {
        qFatal("Failed to query database: %s", qPrintable(query.lastError().text()));
    } else {
        qDebug() << "Order details created";
}
    //TODO add foreign key after all table creation
// "FOREIGN KEY('itemOrderId') REFERENCES itemDetails ( itemOrderId )"
}

void DBManager::createItemTable()
{

    if (QSqlDatabase::database().tables().contains(ITEMSTABLE)) {
        // The table already exists; we don't need to do anything.
        qDebug() << "table exists";
        return;
    }

    QSqlQuery query;
    if (!query.exec(
        "CREATE TABLE IF NOT EXISTS 'itemDetails' ("
        "'itemOrderId' TEXT PRIMARY KEY NOT NULL,"
                "'itemSku' TEXT NOT NULL,"
                "'itemName' Text NOT NULL,"
                "'itemServing' TEXT,"
                "'itemQuantity' Text,"
                "'itemStatus' TEXT NOT NULL,"
                "'itemNumber' Text NOT NULL,"
                "'selectedPosition' INTEGER,"
                "'customerPhone' Text,"
                "'customerName' TEXT,"
                "'customerAddress' Text,"
                "'merchantId' TEXT,"
                "'recipeCuisine' Text,"
                "'recipePrice' TEXT ,"
                "'subTotal' INTEGER, "
                "'discountPercentage' INTEGER, "
                "'discount' INTEGER,"
                "'newCustomerDiscount' INTEGER,"
                "'sgst' INTEGER ,"
                "'cgst' INTEGER ,"
                "'deliveryCharges' INTEGER ,"
                "'totalPrice' INTEGER,"
                "'grCash' INTEGER,"
                "'walletCash' TEXT,"
                "'finalAmount' INTEGER, "
                "'paymentType' Text, "
                "'paymentStatus' Text,"
                "'addNotes' Text,"
                "'deliveryTime' Text,"
                "'orderAt' Text,"
                "'orderCancelTill' Text,"
                "'deliveryExpected' Text,"
                "'dispatchReal' Text"
        ")")) {
        qFatal("Failed to query database: %s", qPrintable(query.lastError().text()));
    } else {
qDebug() << "created tabel item";
}
 //"FOREIGN KEY('ingredientId') REFERENCES IngredientDetails (ingredientId)"
}


