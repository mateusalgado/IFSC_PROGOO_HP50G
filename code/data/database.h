#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlTableModel>
#include <QTableView>
#include <QSqlQuery>
#include <QString>

class Database
{
private:
    QSqlDatabase db;
    QSqlTableModel* settingsTable;
    QSqlTableModel* dataTable;

    bool m_settingsEmpty;
public:
    Database();

    bool isSettingsEmpty();

    void writeSettings(QString brokerAddr, QString mqttTopic);
};

#endif // DATABASE_H
