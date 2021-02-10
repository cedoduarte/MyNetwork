#include "mydatabasemanager.h"
#include "myenums.h"

#include <QTextStream>
#include <QFile>

MyDatabaseManager *MyDatabaseManager::s_db = nullptr;
std::vector<QSqlTableModel *> MyDatabaseManager::s_models;

MyDatabaseManager::MyDatabaseManager(QObject *parent)
    : QObject(parent)
{
    init();
}

MyDatabaseManager::~MyDatabaseManager()
{
    m_db.close();
}

void MyDatabaseManager::init()
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("mynetwork.db");
    m_db.open();
    if (!existsTable("server"))
        executeSqlFile(":sql/server.sql");
    if (!existsTable("client"))
        executeSqlFile(":sql/client.sql");
}

void MyDatabaseManager::initialize()
{
    s_db = new MyDatabaseManager;
}

void MyDatabaseManager::release()
{
    delete s_db;
}

int MyDatabaseManager::getServerPort(int serverId)
{
    QString sql = "select port from server where id = :id";
    QSqlQuery q;
    q.prepare(sql);
    q.bindValue(":id", serverId);
    q.exec();
    q.next();
    return q.value(0).toString().toInt();
}

int MyDatabaseManager::getClientPort(int clientId)
{
    QString sql = "select port from client where id = :id";
    QSqlQuery q;
    q.prepare(sql);
    q.bindValue(":id", clientId);
    q.exec();
    q.next();
    return q.value(0).toString().toInt();
}

QString MyDatabaseManager::getWhichServerIsClientConnected(int clientId)
{
    QString sql = "select ip from client where id = :id";
    QSqlQuery q;
    q.prepare(sql);
    q.bindValue(":id", clientId);
    q.exec();
    q.next();
    return q.value(0).toString();
}

void MyDatabaseManager::setServerPort(int serverId, const QString &port)
{
    QString sql = "update server set port = :port where id = :id";
    QSqlQuery q;
    q.prepare(sql);
    q.bindValue(":port", port);
    q.bindValue(":id", serverId);
    q.exec();
}

void MyDatabaseManager::setClientPort(int clientId, const QString &port)
{
    QString sql = "update client set port = :port where id = :id";
    QSqlQuery q;
    q.prepare(sql);
    q.bindValue(":port", port);
    q.bindValue(":id", clientId);
    q.exec();
}

void MyDatabaseManager::setWhichServerIsClientConnected(int clientId, const QString &ip)
{
    QString sql = "update client set ip = :ip where id = :id";
    QSqlQuery q;
    q.prepare(sql);
    q.bindValue(":ip", ip);
    q.bindValue(":id", clientId);
    q.exec();
}

QSqlTableModel *MyDatabaseManager::getNewModel(const QString &tableName, QObject *parent)
{
    QSqlTableModel *model = new QSqlTableModel(parent);
    model->setTable(tableName);
    model->select();
    s_models.push_back(model);
    return model;
}

void MyDatabaseManager::updateModel(mynet::Model model)
{
    QString tableName = modelToString(model);
    std::for_each(s_models.begin(), s_models.end(), [&](QSqlTableModel *model)
    {
        if (model->tableName() == tableName)
        {
            model->select();
            return;
        }
    });
}

QString MyDatabaseManager::modelToString(mynet::Model model)
{
    switch (model)
    {
        case mynet::Server:
        {
            return "server";
        }
        case mynet::Client:
        {
            return "client";
        }
    }
    return "";
}

void MyDatabaseManager::executeSqlFile(const QString &filepath)
{
    QFile fsql(filepath);
    fsql.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream xin(&fsql);
    while (!xin.atEnd())
    {
        QString sql = xin.readLine();
        if (!sql.isEmpty())
        {
            QSqlQuery q;
            q.prepare(sql);
            q.exec();
        }
    }
    fsql.close();
}

int MyDatabaseManager::getRecordCount(const QString &tableName)
{
    QString sql = "select count(*) from :table";
    QSqlQuery q;
    q.prepare(sql);
    q.bindValue(":table", tableName);
    q.exec();
    if (q.next())
        return q.value(0).toInt();
    return -1;
}

bool MyDatabaseManager::existsTable(const QString &tableName)
{
    if (getRecordCount(tableName) == -1)
        return false;
    return true;
}
