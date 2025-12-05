#include "database.h"

void Database::m_criarTabelaSettings()
{
    QSqlQuery query;
    if (!query.exec("CREATE TABLE IF NOT EXISTS settings ("
                    "broker_addr TEXT, "
                    "broker_port INTEGER,"
                    "save_data BOOL)")) {
        m_showWarning("Erro ao criar tabela settings", query.lastError().text());
    }

    m_settingsTable = new QSqlTableModel();
    m_settingsTable->setTable("settings");
    m_settingsTable->setEditStrategy(QSqlTableModel::OnManualSubmit);
    m_settingsTable->select();

    QTableView *settingsView = new QTableView;
    settingsView->setModel(m_settingsTable);
    settingsView->setWindowTitle("Tabela Settings");
    settingsView->show();
}

void Database::m_criarTabelaDados()
{
    QSqlQuery query;

    if (!query.exec("CREATE TABLE IF NOT EXISTS data ("
                    "time_stamp TEXT, "
                    "station_name TEXT, "
                    "data TEXT)")) {
        m_showWarning("Erro ao criar tabela data", query.lastError().text());
    }

    m_dataTable= new QSqlTableModel();
    m_dataTable->setTable("data");
    m_dataTable->setEditStrategy(QSqlTableModel::OnManualSubmit);
    m_dataTable->select();

    QTableView *dataView = new QTableView;
    dataView->setModel(m_dataTable);
    dataView->setWindowTitle("Tabela Dados");
    dataView->show();
}


void Database::m_showWarning(QString title, QString message)
{
    QMessageBox warning;
    warning.setWindowTitle(title);
    warning.setText(message);
    warning.setDefaultButton(QMessageBox::Ok);
    warning.exec();
}

Database::Database()
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("sema.db");

    if (!m_db.open()) {
        m_showWarning("Erro ao abrir banco de dados", m_db.lastError().text());
        return;
    }

    m_criarTabelaSettings();
    m_criarTabelaDados();
}
