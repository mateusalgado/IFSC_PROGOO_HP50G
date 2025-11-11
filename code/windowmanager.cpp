#include "windowmanager.h"

#include <QLabel>

WindowManager::WindowManager()
{

}

WindowManager::~WindowManager()
{

};

void WindowManager::showSettingsWindow()
{

};

void WindowManager::showDataViewWindow()
{

};

void WindowManager::showDataExportWindow()
{

};

void WindowManager::showEntryWindow()
{
    QLabel* label = new QLabel("<h1 style=\"color:blue;\">SEMA</h1>");
    label->show();
};
