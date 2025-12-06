#include "winmanager.h"

WinManager::WinManager()
{
    database = new Database();
    auto settings = database->getSettings();

    m_dashboardWin = new DashboardWin();
    m_settingsWin  = new SettingsWin();
    m_netManager = new NetManager();

    m_settingsWin->loadSettings(settings);
    m_netManager->updateSettings(settings);
    m_dashboardWin->updateMaxData(settings.maxData);

    createSignals();

    database->loadMessages();
}

void WinManager::showSettings()
{
    m_settingsWin->show();
}

void WinManager::showDashboard()
{
    m_dashboardWin->show();
}

void WinManager::createSignals()
{
    connect(m_dashboardWin->bSettings, &CustomButton::clicked, m_settingsWin, &QWidget::show);

    connect(m_dashboardWin->bConnect, &CustomButton::clicked, this, [this](){
        m_dashboardWin->bConnect->setDisabled(true);
        m_netManager->connectionRequest();
    });

    connect(m_settingsWin, &SettingsWin::settingsChanged, this, [this](const SettingsData &data){
        database->saveSettings(data);
        m_netManager->updateSettings(data);
        m_dashboardWin->updateMaxData(data.maxData);
    });

    connect(m_netManager, &NetManager::connected, this, [this](){
        m_dashboardWin->bConnect->setEnabled(true);
        m_dashboardWin->bConnect->setText("Desconectar");
        m_dashboardWin->bConnect->update();
    });

    connect(m_netManager, &NetManager::errorChanged, this, [this](){
        m_dashboardWin->bConnect->setEnabled(true);
        m_dashboardWin->bConnect->setText("Conectar");
        m_dashboardWin->bConnect->update();
    });

    connect(m_netManager, &NetManager::disconnected, this, [this](){
        m_dashboardWin->bConnect->setEnabled(true);
        m_dashboardWin->bConnect->setText("Conectar");
        m_dashboardWin->bConnect->update();
    });

    connect(database, &Database::loadedMessage, this, [this](const QString &topic, const QString &time, const QString &raw){
        m_dashboardWin->plotData(topic, time, raw);
    });
    connect(database, &Database::erased, m_dashboardWin, &DashboardWin::erase);

    connect(m_netManager, &NetManager::log, m_dashboardWin, &DashboardWin::log);
    connect(m_netManager, &NetManager::message, database, &Database::saveData);
    connect(m_netManager, &NetManager::message, m_dashboardWin, &DashboardWin::plotData);

    connect(m_dashboardWin->bData, &CustomButton::clicked, database, &Database::exportData);
    connect(m_dashboardWin->bEraseData, &CustomButton::clicked, database, &Database::eraseData);

}
