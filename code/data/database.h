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
#include <QMessageBox>

class Database
{
private:
    QSqlDatabase m_db;

    QSqlTableModel* m_settingsTable;
    QSqlTableModel* m_dataTable;

    void m_criarTabelaSettings();
    void m_criarTabelaDados();

    void m_showWarning(QString title, QString message);
public:
    Database();
};

#endif // DATABASE_H
