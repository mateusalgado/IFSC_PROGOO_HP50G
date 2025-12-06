#ifndef DASHBOARDWIN_H
#define DASHBOARDWIN_H

#include <QWidget>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSize>
#include <QApplication>

#include "../widgets/customchart.h"
#include "../widgets/customlabel.h"
#include "../widgets/custombutton.h"

class DashboardWin : public QWidget
{
    Q_OBJECT
public:
    explicit DashboardWin(QWidget *parent = nullptr);

    CustomLabel<int>* lOnlineCount;
    CustomLabel<float>* lAvgAirTemp;
    CustomLabel<float>* lAvgAirHum;
    CustomLabel<float>* lAvgWaterTemp;
    CustomLabel<int>* lAvgUV;

    CustomChart* cAirTemp;
    CustomChart* cAirHum;
    CustomChart* cWaterTemp;
    CustomChart* cUV;

    CustomButton* bSettings;
    CustomButton* bData;
    CustomButton* bConnect;

protected:
    void closeEvent(QCloseEvent *event) override;

private:
    QGridLayout* m_chartsLayout;
    QVBoxLayout* m_labelsandButtonsLayout;
    QVBoxLayout* m_labelsLayout;
    QVBoxLayout* m_buttonsLayout;

    QHBoxLayout* m_dataLayout;

    void createButtons();
    void createLabels();
    void createCharts();
    void createLayouts();

signals:

};

#endif // DASHBOARDWIN_H
