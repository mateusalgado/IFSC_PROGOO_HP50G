#ifndef SETTINGSWIN_H
#define SETTINGSWIN_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>

#include "database.h"

class SettingsWin : QObject
{
public:
    SettingsWin(Database* db);

    void show();
    void save();

private:
    Database* m_settingsDb;

    QWidget* m_settingsWin;

    QVBoxLayout* m_mainlay;
    QHBoxLayout* m_buttonslay;

    QLabel* m_brokerAddrLabel;
    QLabel* m_mqttTopicLabel;

    QLineEdit* m_brokerAddrInput;
    QLineEdit* m_mqttTopicInput;

    QPushButton* m_saveButton;
    QPushButton* m_cancelButton;
};

#endif // SETTINGSWIN_H
