#include "winmanager.h"

WinManager::WinManager()
{
    database = new Database();
    m_dashboardWin = new DashboardWin();
    m_settingsWin  = new SettingsWin();
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
    QObject::connect(m_dashboardWin->bSettings, &CustomButton::clicked, m_settingsWin, &QWidget::show);
}
