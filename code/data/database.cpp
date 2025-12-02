#include "database.h"
#include <QDebug>

Database::Database()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("sema.db");

    if (!db.open()) {
        qDebug() << "Erro ao abrir db:" << db.lastError().text();
        return;
    }

    QSqlQuery query;
    if (!query.exec(
            "CREATE TABLE IF NOT EXISTS settings ("
            "brokerAddr TEXT NOT NULL,"
            "mqttTopic  TEXT NOT NULL)"
            )) {
        qDebug() << "Erro ao criar tabela settings:" << query.lastError();
    }

    settingsTable = new QSqlTableModel();
    settingsTable->setTable("settings");
    settingsTable->setEditStrategy(QSqlTableModel::OnManualSubmit);
    settingsTable->select();

    m_settingsEmpty = settingsTable->rowCount() == 0;

    QTableView *view = new QTableView;
    view->setModel(settingsTable);
    view->show();
}


bool Database::isSettingsEmpty()
{
    return this->m_settingsEmpty;
}

void Database::writeSettings(QString brokerAddr, QString mqttTopic)
{
    auto record = settingsTable->record(0);
    record.setValue("brokerAddr", brokerAddr);
    record.setValue("mqttTopic", mqttTopic);

    if (!settingsTable->insertRecord(0, record)) {
        qDebug() << "Erro ao gravar configurações:" << settingsTable->lastError().text();
        return;
    }

    if (!settingsTable->submitAll()) {
        qDebug() << "Erro ao gravar alterações:" << settingsTable->lastError().text();
    } else {
        m_settingsEmpty = false;
    }

}
