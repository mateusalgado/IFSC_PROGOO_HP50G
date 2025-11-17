#include <QApplication>
#include "settingswin.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    SettingsWin settingsWin;
    settingsWin.show();

    return app.exec();
}
