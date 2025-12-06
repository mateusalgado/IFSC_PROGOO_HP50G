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

    createSignals();
}

void WinManager::showSettings()
{
    m_settingsWin->show();
}

void WinManager::showDashboard()
{
    m_dashboardWin->show();
}

void WinManager::showDataExport()
{

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
    });

    connect(m_netManager, &NetManager::connected, this, [this](){
        m_dashboardWin->bConnect->setEnabled(true);
        m_dashboardWin->bConnect->setText("Disconectar");
    });

    connect(m_netManager, &NetManager::disconnected, this, [this](){
        m_dashboardWin->bConnect->setEnabled(true);
        m_dashboardWin->bConnect->setText("Conectar");
    });
}
