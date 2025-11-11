#include "windowmanager.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    WindowManager winManager;
    winManager.showEntryWindow();

    return app.exec();
}
