#ifndef SEMA_WINMAN_H
#define SEMA_WINMAN_H

#include <QWidget>

class WindowManager : public QWidget
{
    Q_OBJECT

public:
    WindowManager(QWidget *parent = nullptr);
    ~WindowManager();

private:
};
#endif // SEMA_WINMAN_H
