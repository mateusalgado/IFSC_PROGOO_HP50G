#include <QApplication>
#include "settingswin.h"
#include "database.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Database db;
    SettingsWin settingsWin(&db);

    if(db.isSettingsEmpty())
    {
        settingsWin.show();
    };

    return app.exec();
}
