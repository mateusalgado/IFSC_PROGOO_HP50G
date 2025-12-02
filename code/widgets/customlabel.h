#ifndef CUSTOMLABEL_H
#define CUSTOMLABEL_H

#include <QWidget>
#include <QString>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QBoxLayout>
#include <QVariant>
#include <QIcon>

template<typename T>
class CustomLabel : public QWidget
{
private:
    QLabel* m_lTitle;
    QLabel* m_lInfo;
    QBoxLayout* m_layout;

    QString m_dataUnity;

    T m_data;
    bool m_hasReceivedData;

    QIcon* icon;
public:
    explicit CustomLabel(QString title, QString iconPath, int iconW, int iconH, QBoxLayout::Direction direction,  bool vertical = false, QWidget *parent = nullptr)
    {
        m_lTitle = new QLabel(title);

        icon = new QIcon(iconPath);
        m_lInfo = new QLabel();
        m_lInfo->setPixmap(icon->pixmap(iconW, iconH));
        m_lInfo->setAttribute(Qt::WA_TranslucentBackground);

        if(vertical)
            m_layout = new QVBoxLayout();
        else
            m_layout = new QHBoxLayout();

        m_layout->setDirection(direction);
        m_layout->addWidget(m_lTitle);
        m_layout->addWidget(m_lInfo);
        this->setLayout(m_layout);
    }

    explicit CustomLabel(QString title, QWidget *parent = nullptr)
    {
        m_lTitle = new QLabel(title);
        m_layout = new QHBoxLayout();
        m_layout->addWidget(m_lTitle);
        this->setLayout(m_layout);
    }

    explicit CustomLabel(QString title, QString dataUnity, bool vertical = true, QWidget *parent = nullptr)
    {
        m_hasReceivedData = false;
        m_dataUnity = dataUnity;

        m_lTitle = new QLabel(title);
        m_lInfo = new QLabel(QString("-%1").arg(m_dataUnity));

        if(vertical)
            m_layout = new QVBoxLayout();
        else
            m_layout = new QHBoxLayout();

        m_layout->addWidget(m_lTitle);
        m_layout->addWidget(m_lInfo);

        this->setContentsMargins(0,0,0,0);
        this->setLayout(m_layout);

    }

public slots:
    void setData(T newData)
    {
        m_data = newData;
        m_hasReceivedData = true;

        QVariant v;
        v.setValue(newData);

        if(m_lInfo != nullptr)
            if(!m_dataUnity.isNull())
                this->m_lInfo->setText(QString("%1%2").arg(v.toString(), m_dataUnity));
    }

    T getData()
    {
        return this->m_data;
    }
signals:
};

#endif // CUSTOMLABEL_H
