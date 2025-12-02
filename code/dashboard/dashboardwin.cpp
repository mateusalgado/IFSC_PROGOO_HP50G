#include "dashboardwin.h"

DashboardWin::DashboardWin(QWidget *parent)
    : QWidget{parent}
{
    createLabels();
    createCharts();
    createLayouts();

    resize(800, 600);
}

void DashboardWin::createLabels()
{
    m_lOnlineCount = new CustomLabel<int>("Estações conectadas", "", false);
    m_lOnlineCount->setData(0);

    m_lAvgAirHum = new CustomLabel<float>("Umidade média", "%");
    m_lAvgAirTemp = new CustomLabel<float>("Temp. Ar média", "°C");
    m_lAvgWaterTemp = new CustomLabel<float>("Temp. Água média", "°C");
    m_lAvgUV = new CustomLabel<int>("Índice UV médio", "°C");
}

void DashboardWin::createCharts()
{
    m_gAirTemp = new CustomChart("://img/temperature.png", 20, 20);
    m_gAirHum = new CustomChart("://img/humidity.png", 20, 20);
    m_gWaterTemp = new CustomChart("://img/water.png", 20, 20);
    m_gUV = new CustomChart("://img/uv.png", 20, 20);
}

void DashboardWin::createLayouts()
{

    //Layout para os dados médios
    m_labelsLayout = new QVBoxLayout();
    m_labelsLayout->addWidget(m_lOnlineCount);
    m_labelsLayout->addWidget(m_lAvgAirHum);
    m_labelsLayout->addWidget(m_lAvgAirTemp);
    m_labelsLayout->addWidget(m_lAvgUV);
    m_labelsLayout->addWidget(m_lAvgWaterTemp);
    m_labelsLayout->setAlignment(Qt::AlignTop);
    m_labelsLayout->setSpacing(25);

    //Layout em grid para os gráficos
    m_chartsLayout = new QGridLayout();
    m_chartsLayout->addLayout(m_gAirHum, 0, 0);
    m_chartsLayout->addLayout(m_gAirTemp, 0, 1);
    m_chartsLayout->addLayout(m_gUV, 1, 0);
    m_chartsLayout->addLayout(m_gWaterTemp, 1, 1);

    //Separa o layout dos dados médios do layout dos gráficos
    m_dataLayout = new QHBoxLayout();
    m_dataLayout->addLayout(m_labelsLayout);
    m_dataLayout->addLayout(m_chartsLayout);
    m_dataLayout->setAlignment(Qt::AlignCenter | Qt::AlignHCenter | Qt::AlignVCenter);
    this->setLayout(m_dataLayout);

}
