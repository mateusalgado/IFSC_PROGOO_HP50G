#ifndef SETTINGSWIN_H
#define SETTINGSWIN_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>

class SettingsWin : QObject
{
public:
    SettingsWin();

    void show();
    void save();

private:
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
