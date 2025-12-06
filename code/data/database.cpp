#include "database.h"

Database::Database()
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("sema.db");

    if (!m_db.open()) {
        QMessageBox::warning(nullptr, "Erro ao abrir banco de dados", m_db.lastError().text());
        return;
    }

    m_criarTabelaSettings();
    m_criarTabelaDados();
}

void Database::m_criarTabelaSettings()
{
    QSqlQuery query;
    if (!query.exec("CREATE TABLE IF NOT EXISTS settings ("
                    "key TEXT PRIMARY KEY,"
                    "value TEXT"
                    ");"))
    QMessageBox::warning(nullptr, "Erro ao criar tabela settings", query.lastError().text());

    m_settingsTable = new QSqlTableModel();
    m_settingsTable->setTable("settings");
    m_settingsTable->setEditStrategy(QSqlTableModel::OnManualSubmit);
    m_settingsTable->select();

    QTableView *settingsView = new QTableView;
    settingsView->setModel(m_settingsTable);
    settingsView->setWindowTitle("Tabela Settings");
    settingsView->setWindowIcon(QIcon("://img/settings.png"));
    settingsView->show();
}

void Database::m_criarTabelaDados()
{
    QSqlQuery query;

    if (!query.exec("CREATE TABLE IF NOT EXISTS data ("
                    "time_stamp TEXT, "
                    "station_name TEXT, "
                    "data TEXT)"))
    QMessageBox::warning(nullptr, "Erro ao criar tabela data", query.lastError().text());


    m_dataTable= new QSqlTableModel();
    m_dataTable->setTable("data");
    m_dataTable->setEditStrategy(QSqlTableModel::OnManualSubmit);
    m_dataTable->select();

    QTableView *dataView = new QTableView;
    dataView->setModel(m_dataTable);
    dataView->setWindowTitle("Tabela Dados");
    dataView->setWindowIcon(QIcon("://img/database.png"));
    dataView->show();
}

void Database::m_setSetting(const QString &key, const QString &value)
{
    QSqlQuery query;
    query.prepare("UPDATE settings SET value = :value WHERE key = :key");
    query.bindValue(":value", value);
    query.bindValue(":key", key);
    query.exec();

    if (query.numRowsAffected() == 0) {
        QSqlQuery q2;
        q2.prepare("INSERT INTO settings (key, value) VALUES (:key, :value)");
        q2.bindValue(":key", key);
        q2.bindValue(":value", value);
        if (!q2.exec()) {
            QMessageBox::warning(nullptr, "Erro ao inserir setting", q2.lastError().text());
        }
    }
}

void Database::saveSettings(const SettingsData &data)
{
    if (!m_db.isOpen())
    {
        QMessageBox::warning(nullptr, "Erro ao abrir banco de dados", m_db.lastError().text());
        return;
    }
    m_setSetting("brokerAddr", data.brokerAddr);
    m_setSetting("brokerPort", QString::number(data.brokerPort));
    m_setSetting("saveData", data.saveData ? "1" : "0");
    m_setSetting("username", data.username);
    m_setSetting("pass", data.pass);

    m_settingsTable->select();
}

SettingsData Database::getSettings()
{
    SettingsData data;

    data.brokerAddr = "";
    data.brokerPort = 1;
    data.saveData   = false;
    data.username = "";
    data.pass = "";

    if (!m_db.isOpen())
    {
        QMessageBox::warning(nullptr, "Erro ao abrir banco de dados", m_db.lastError().text());
        return data;
    }

    QSqlQuery query;

    query.prepare("SELECT value FROM settings WHERE key = 'brokerAddr'");
    if (query.exec() && query.next()) {
        data.brokerAddr = query.value(0).toString();
    }

    query.prepare("SELECT value FROM settings WHERE key = 'username'");
    if (query.exec() && query.next()) {
        data.username = query.value(0).toString();
    }

    query.prepare("SELECT value FROM settings WHERE key = 'pass'");
    if (query.exec() && query.next()) {
        data.pass = query.value(0).toString();
    }

    query.prepare("SELECT value FROM settings WHERE key = 'brokerPort'");
    if (query.exec() && query.next()) {
        data.brokerPort = query.value(0).toInt();
    }

    query.prepare("SELECT value FROM settings WHERE key = 'saveData'");
    if (query.exec() && query.next()) {
        data.saveData = query.value(0).toString() == "1";
    }

    return data;
}
