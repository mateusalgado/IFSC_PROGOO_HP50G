#include "settingswin.h"


SettingsWin::SettingsWin()
{
    //Construtores
    m_settingsWin = new QWidget();
    m_mainlay = new QVBoxLayout(m_settingsWin);
    m_buttonslay = new QHBoxLayout();

    m_brokerAddrLabel = new QLabel("Endereço Broker");
    m_mqttTopicLabel = new QLabel("Tópico MQTT");

    m_saveButton = new QPushButton("Salvar");
    m_cancelButton = new QPushButton("Cancelar");

    m_brokerAddrInput = new QLineEdit();
    m_mqttTopicInput = new QLineEdit();

    //Botões
    QObject::connect(m_cancelButton, SIGNAL(clicked()), m_settingsWin, SLOT(close()));

    connect(m_saveButton, &QPushButton::clicked, this, [this] {
        save();
    });

    //Layout Botões
    m_buttonslay->addWidget(m_cancelButton);
    m_buttonslay->addWidget(m_saveButton);
    m_buttonslay->setAlignment(Qt::AlignCenter);

    //Layout Principal
    m_mainlay->setAlignment(Qt::AlignCenter);
    m_mainlay->setSpacing(5);

    m_mainlay->addWidget(m_brokerAddrLabel);
    m_mainlay->addWidget(m_brokerAddrInput);

    m_mainlay->addSpacing(10);

    m_mainlay->addWidget(m_mqttTopicLabel);
    m_mainlay->addWidget(m_mqttTopicInput);

    m_mainlay->addSpacing(5);

    m_mainlay->addLayout(m_buttonslay);

    //Janela
    m_settingsWin->setWindowTitle("Configurações");
    m_settingsWin->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    m_settingsWin->setFixedSize(m_settingsWin->sizeHint());
}

void SettingsWin::show()
{
    m_settingsWin->show();
    m_mqttTopicInput->clearFocus();
    m_brokerAddrInput->clearFocus();
}

void SettingsWin::save()
{
    QLabel* label = new QLabel("Teste");
    label->show();
}
