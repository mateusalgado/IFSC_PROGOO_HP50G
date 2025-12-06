#ifndef WINMANAGER_H
#define WINMANAGER_H

#include "settings/settingswin.h"
#include "dashboard/dashboardwin.h"
#include "data/database.h"
#include "networking/netmanager.h"

#include <QObject>

class WinManager : QObject
{
    Q_OBJECT

public:
    Database* database;
    WinManager();

    void showSettings();
    void showDashboard();

    void createSignals();

private:
    SettingsWin* m_settingsWin;
    DashboardWin* m_dashboardWin;
    NetManager* m_netManager;
};

#endif // WINMANAGER_H
