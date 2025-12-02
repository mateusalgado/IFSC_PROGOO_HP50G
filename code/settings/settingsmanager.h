#ifndef SETTINGSMANAGER_H
#define SETTINGSMANAGER_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>

#include "../data/database.h"

class SettingsManager : QObject
{
public:
    SettingsManager();

    void show();
    void save();

    bool isSettingsEmpty();

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

#endif // SETTINGSMANAGER_H
