#ifndef DASHBOARDWIN_H
#define DASHBOARDWIN_H

#include <QWidget>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSize>
#include <QApplication>
#include <QTextEdit>
#include <QStringList>
#include <QMessageBox>

#include "../widgets/customchart.h"
#include "../widgets/customlabel.h"
#include "../widgets/custombutton.h"

class DashboardWin : public QWidget
{
    Q_OBJECT
public:
    explicit DashboardWin(QWidget *parent = nullptr);

    CustomLabel* lAvgAirTemp;
    CustomLabel* lAvgAirHum;
    CustomLabel* lAvgWaterTemp;
    CustomLabel* lAvgUV;
    QTextEdit* lLog;

    CustomChart* cAirTemp;
    CustomChart* cAirHum;
    CustomChart* cWaterTemp;
    CustomChart* cUV;

    CustomButton* bSettings;
    CustomButton* bData;
    CustomButton* bEraseData;
    CustomButton* bConnect;
    CustomButton* bClearLog;

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

public slots:
    void log(QString messaage);
    void plotData(const QString &topic, const QString &time, const QString &raw);
    void updateMaxData(const long& maxData);
    void erase();
signals:

};

#endif // DASHBOARDWIN_H
