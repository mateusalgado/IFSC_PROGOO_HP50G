#ifndef CUSTOMLABEL_H
#define CUSTOMLABEL_H

#include <QWidget>
#include <QString>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QBoxLayout>
#include <QVariant>
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
public:
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

        this->m_lInfo->setText(QString("%1%2").arg(v.toString(), m_dataUnity));
    }

    T getData()
    {
        return this->m_data;
    }
signals:
};

#endif // CUSTOMLABEL_H
