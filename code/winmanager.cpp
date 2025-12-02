#include "winmanager.h"

WinManager::WinManager()
{
    createSignals();
}

void WinManager::showSettings()
{
    m_settingsWin.show();
}

void WinManager::showDashboard()
{
    m_dashboardWin.show();
}

void WinManager::showDataExport()
{

}

void WinManager::createSignals()
{
    QObject::connect(m_dashboardWin.bSettings, &CustomButton::clicked, &m_settingsWin, &QWidget::show);
}
