#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QPainter>
#include <QPaintEvent>
#include <QTimer>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    /* 重写父类下的 protected 方法*/
protected:
    void paintEvent(QPaintEvent *);

    private:
    /* 定时器，用于定时更新界面 */
    QTimer *timer;
    /* 角度 */
    int angle;

    private slots:
    /* 槽函数 */
    void timerTimeOut();
};
#endif // MAINWINDOW_H
