#include "dashboardwin.h"

DashboardWin::DashboardWin(QWidget *parent)
    : QWidget{parent}
{
    createLabels();
    createButtons();
    createCharts();
    createLayouts();

    resize(800, 600);

    setWindowIcon(QIcon("://img/sema.png"));
}

void DashboardWin::closeEvent(QCloseEvent *event)
{
    QApplication::quit();
    event->accept();
}

void DashboardWin::createButtons()
{
    bSettings = new CustomButton(" Configurar", "://img/settings.png", 22, 22);
    bData = new CustomButton(" Exportar", "://img/database.png", 22, 22);
}

void DashboardWin::createLabels()
{
    lOnlineCount = new CustomLabel<int>("Estações conectadas", "");
    lOnlineCount->setData(0);

    lAvgAirHum = new CustomLabel<float>("Umidade média", "%");
    lAvgAirTemp = new CustomLabel<float>("Temp. Ar média", "°C");
    lAvgWaterTemp = new CustomLabel<float>("Temp. Água média", "°C");
    lAvgUV = new CustomLabel<int>("Índice UV médio", "°C");
}

void DashboardWin::createCharts()
{
    cAirTemp = new CustomChart();
    cAirHum = new CustomChart();
    cWaterTemp = new CustomChart();
    cUV = new CustomChart();
}

void DashboardWin::createLayouts()
{

    //Layout para os dados médios e botões
    m_labelsLayout = new QVBoxLayout();
    m_labelsLayout->addWidget(lOnlineCount);
    m_labelsLayout->addWidget(lAvgAirHum);
    m_labelsLayout->addWidget(lAvgAirTemp);
    m_labelsLayout->addWidget(lAvgUV);
    m_labelsLayout->addWidget(lAvgWaterTemp);
    m_labelsLayout->addWidget(bData);
    m_labelsLayout->addWidget(bSettings);
    m_labelsLayout->setAlignment(Qt::AlignTop);
    m_labelsLayout->setSpacing(25);

    //Layout em grid para os gráficos
    m_chartsLayout = new QGridLayout();
    m_chartsLayout->addLayout(cAirHum, 0, 0);
    m_chartsLayout->addLayout(cAirTemp, 0, 1);
    m_chartsLayout->addLayout(cUV, 1, 0);
    m_chartsLayout->addLayout(cWaterTemp, 1, 1);

    //Separa o layout dos dados médios VS layout dos gráficos
    m_dataLayout = new QHBoxLayout();
    m_dataLayout->addLayout(m_labelsLayout);
    m_dataLayout->addLayout(m_chartsLayout);
    m_dataLayout->setAlignment(Qt::AlignCenter | Qt::AlignHCenter | Qt::AlignVCenter);
    this->setLayout(m_dataLayout);

}
