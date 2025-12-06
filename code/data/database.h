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
#include <QObject>
#include "../settings/settingswin.h"
#include <QFile>
#include <QFileDialog>

class Database : public QObject
{
    Q_OBJECT
private:
    QSqlDatabase m_db;

    QSqlTableModel* m_settingsTable;
    QSqlTableModel* m_dataTable;

    void m_criarTabelaSettings();
    void m_criarTabelaDados();

    void m_setSetting(const QString &key, const QString &value);
public:
    Database();
    SettingsData getSettings();

public slots:
    void eraseData();
    void exportData();

    void saveData(const QString &topic, const QString &time, const QString &raw);
    void saveSettings(const SettingsData& data);
};

#endif // DATABASE_H
