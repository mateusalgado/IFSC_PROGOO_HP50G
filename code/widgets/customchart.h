#ifndef CUSTOMCHART_H
#define CUSTOMCHART_H

#include <QStackedLayout>
#include <QLabel>
#include <QIcon>
#include <QChartView>
#include <QString>
#include <QDebug>
#include <QSize>

class CustomChart : public QStackedLayout
{
    Q_OBJECT
public:
    CustomChart()
    {
        view = new QChartView();
        addWidget(view);
    }

    CustomChart(QString iconPath, int iconW, int iconH)
    {
        icon = new QIcon(iconPath);
        label = new QLabel();
        label->setPixmap(icon->pixmap(QSize(iconW, iconH)));
        label->setAttribute(Qt::WA_TranslucentBackground);
        label->setAlignment(Qt::AlignLeft | Qt::AlignTop);
        label->setContentsMargins(15, 15, 0, 0);

        view = new QChartView();
        view->layout()->setContentsMargins(0, 0, 0, 0);
        view->setContentsMargins(0,0,0,0);

        addWidget(view);
        addWidget(label);
        setStackingMode(QStackedLayout::StackAll);
    }
private:
    QChartView* view;
    QLabel* label;
    QIcon* icon;
};

#endif // CUSTOMCHART_H
