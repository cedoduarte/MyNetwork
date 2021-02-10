#ifndef MYDATABASEMANAGER_H
#define MYDATABASEMANAGER_H

#include "myenums.h"
#include <vector>
#include <QObject>
#include <QVariant>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlTableModel>

/** database manager */
class MyDatabaseManager : public QObject
{
    Q_OBJECT
public:
    /** initialize database */
    static void initialize();

    /** release database */
    static void release();

    /** get server port */
    static int getServerPort(int serverId);

    /** get client port */
    static int getClientPort(int clientId);

    /** which server is client connected? */
    static QString getWhichServerIsClientConnected(int clientId);

    /** set server port */
    static void setServerPort(int serverId, const QString &port);

    /** set client port */
    static void setClientPort(int clientId, const QString &port);

    /** set which server is client connected */
    static void setWhichServerIsClientConnected(int clientId, const QString &ip);

    /** get new sql table model */
    static QSqlTableModel *getNewModel(const QString &tableName, QObject *parent = nullptr);

    /** update sql table model */
    static void updateModel(mynet::Model model);
private:
    /** convert model to string */
    static QString modelToString(mynet::Model model);

    /** execute sql file */
    static void executeSqlFile(const QString &filepath);

    /** get record count */
    static int getRecordCount(const QString &tableName);

    /** exists table */
    static bool existsTable(const QString &tableName);

    static MyDatabaseManager *s_db; //!< global database instance
    static std::vector<QSqlTableModel *> s_models; //!< models

    /** constructor */
    explicit MyDatabaseManager(QObject *parent = nullptr);

    /** destructor */
    virtual ~MyDatabaseManager();

    /** initialize */
    void init();

    QSqlDatabase m_db; //!< database
};

#endif // MYDATABASEMANAGER_H
