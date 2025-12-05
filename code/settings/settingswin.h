#ifndef SETTINGSWIN_H
#define SETTINGSWIN_H

#include <QWidget>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QCheckBox>
#include "../widgets/custombutton.h"

class SettingsWin : public QWidget
{
    Q_OBJECT
public:
    explicit SettingsWin(QWidget *parent = nullptr);

    CustomButton* bSave;

    QLineEdit* lAddr;
    QLineEdit* lPort;
    QCheckBox* cSaveData;
private:
    void createButtons();
    void createInputs();
    void createLayout();

    QIcon* icon;

    QVBoxLayout* layout;

signals:
};

#endif // SETTINGSWIN_H
