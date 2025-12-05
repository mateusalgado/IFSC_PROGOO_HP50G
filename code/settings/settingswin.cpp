#include "settingswin.h"

SettingsWin::SettingsWin(QWidget *parent)
    : QWidget{parent}
{
    createButtons();
    createInputs();
    createLayout();
}

void SettingsWin::createButtons()
{
    bSave = new CustomButton(" Salvar", "://img/save.png", 22, 22);
    cSaveData = new QCheckBox("Salvar dados recebidos");
}

void SettingsWin::createInputs()
{
    lAddr = new QLineEdit();
    lAddr->setPlaceholderText("Endereço Broker MQTT");

    lPort =new QLineEdit();
    lPort->setPlaceholderText("Porta Broker MQTT");
}

void SettingsWin::createLayout()
{
    layout = new QVBoxLayout();

    layout->addWidget(lAddr);
    layout->addWidget(lPort);
    layout->addWidget(cSaveData);
    layout->addWidget(bSave);

    setLayout(layout);

    icon = new QIcon("://img/settings.png");
    setWindowIcon(*icon);
    setWindowTitle("Configurações");
    setFixedSize(sizeHint());
}
