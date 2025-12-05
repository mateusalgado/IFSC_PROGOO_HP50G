#include "settingswin.h"

SettingsWin::SettingsWin(QWidget *parent)
    : QWidget{parent}
{
    createButtons();
    createInputs();
    createLayout();

    connect(bSave, &QPushButton::clicked, this, &SettingsWin::onSaveClicked);
}

void SettingsWin::loadSettings(const SettingsData &data)
{
    lAddr->setText(data.brokerAddr);
    lPort->setText(QString::number(data.brokerPort));
    cSaveData->setChecked(data.saveData);
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
    lPort->setValidator(new QIntValidator(0, 9999, this));
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
    setWindowIcon(QIcon("://img/settings.png"));
    setWindowTitle("Configurações");
    setFixedSize(sizeHint().width() + 100, sizeHint().height());
}

void SettingsWin::onSaveClicked()
{
    bool ok;
    int port = lPort->text().toInt(&ok);

    if (!ok || port < 1 || port > 65535) {
        QMessageBox::warning(this, "Porta inválida",
                             "Insira uma porta válida entre 1 e 65535.");
        return;
    }

    if (lAddr->text().isEmpty()) {
        QMessageBox::warning(this, "Endereço vazio",
                             "O endereço do broker não pode estar vazio.");
        return;
    }

    SettingsData data;
    data.brokerAddr = lAddr->text();
    data.brokerPort = port;
    data.saveData   = cSaveData->isChecked();

    emit settingsChanged(data);
    close();
}

