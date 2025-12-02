#ifndef WINMANAGER_H
#define WINMANAGER_H

#include "settingswin.h"
#include "dashboardwin.h"

class WinManager
{
public:
    WinManager();

    void showSettings();
    void showDashboard();
    void showDataExport();

private:
    SettingsWin m_settingsWin;
    DashboardWin m_dashboardWin;
};

#endif // WINMANAGER_H
