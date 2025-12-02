#ifndef WINMANAGER_H
#define WINMANAGER_H

#include "settings/settingswin.h"
#include "dashboard/dashboardwin.h"

#include <QObject>

class WinManager : QObject
{
    Q_OBJECT
public:
    WinManager();

    void showSettings();
    void showDashboard();
    void showDataExport();

    void createSignals();

private:
    SettingsWin m_settingsWin;
    DashboardWin m_dashboardWin;
};

#endif // WINMANAGER_H
