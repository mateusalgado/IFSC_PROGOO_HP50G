#include "netmanager.h"

NetManager::NetManager(QObject *parent)
    : QObject{parent}
{
    cli = new QMqttClient(this);
    cli->setProtocolVersion(QMqttClient::MQTT_3_1_1);

    connect(cli, &QMqttClient::messageReceived,
            this, &NetManager::proccessMessage);

    connect(cli, &QMqttClient::stateChanged, this, [this](QMqttClient::ClientState s){
        emit log("MQTT State changed: " + QString::number(s));
    });

    connect(cli, &QMqttClient::errorChanged, this, [this](QMqttClient::ClientError e){
        emit log("MQTT Error changed: " + QString::number(e));
        emit errorChanged();
    });

    connect(cli, &QMqttClient::connected, this, [this](){
        emit log("MQTT conectado.");
        cli->subscribe(QMqttTopicFilter(m_settingsData.topico));
        emit connected();
    });

    connect(cli, &QMqttClient::disconnected, this, [this](){
        emit log("MQTT disconectado.");
        emit disconnected();
    });
}


void NetManager::proccessMessage(const QByteArray &message,
                                 const QMqttTopicName &topic)
{
    QString payload = QString::fromUtf8(message);

    QString content = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")
                      + " Message: " + payload + "\n"
                      + "Topic: " + topic.name();

    QMessageBox::information(nullptr, "MQTT Message", content);
}

void NetManager::connectionRequest()
{
    if(cli == nullptr) return;

    if(cli->state() == QMqttClient::Connected)
    {
        cli->disconnectFromHost();
        return;
    }

    if(cli->state() == QMqttClient::Disconnected)
    {
        QSslConfiguration sslConfig = QSslConfiguration::defaultConfiguration();
        sslConfig.setPeerVerifyMode(QSslSocket::VerifyPeer);
        sslConfig.setProtocol(QSsl::TlsV1_2OrLater);
        cli->connectToHostEncrypted(sslConfig);
    }
}

void NetManager::updateSettings(const SettingsData& data)
{
    m_settingsData = data;
    if(cli == nullptr) return;

    cli->setUsername(m_settingsData.username);
    cli->setPassword(m_settingsData.pass);
    cli->setHostname(m_settingsData.brokerAddr);
    cli->setPort(static_cast<quint16>(m_settingsData.brokerPort));

    if(cli->state() == QMqttClient::Connected)
        cli->subscribe(QMqttTopicFilter(m_settingsData.topico));
}
