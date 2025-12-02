#ifndef DASHBOARDWIN_H
#define DASHBOARDWIN_H

#include <QWidget>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QChartView>
#include <QSize>
#include <QDebug>

#include "../widgets/customchart.h"
#include "../widgets/customlabel.h"

class DashboardWin : public QWidget
{
    Q_OBJECT
public:
    explicit DashboardWin(QWidget *parent = nullptr);
private:
    CustomLabel<int>* m_lOnlineCount;
    CustomLabel<float>* m_lAvgAirTemp;
    CustomLabel<float>* m_lAvgAirHum;
    CustomLabel<float>* m_lAvgWaterTemp;
    CustomLabel<int>* m_lAvgUV;

    CustomChart* m_gAirTemp;
    CustomChart* m_gAirHum;
    CustomChart* m_gWaterTemp;
    CustomChart* m_gUV;

    QGridLayout* m_chartsLayout;
    QVBoxLayout* m_labelsLayout;
    QHBoxLayout* m_dataLayout;

    void createLabels();
    void createCharts();
    void createLayouts();
signals:

};

#endif // DASHBOARDWIN_H
