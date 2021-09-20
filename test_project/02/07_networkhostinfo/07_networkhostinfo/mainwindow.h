#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTextBrowser>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTimer>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    /* 点击获取和清空文本按钮 */
    QPushButton *pushButton[2];

    /* 文本浏览框用于显示本机的信息 */
    QTextBrowser *textBrowser;

    /* 水平 Widget 容器和垂直 Widget 容器*/
    QWidget *hWidget;
    QWidget *vWidget;

    /* 水平布局和垂直布局 */
    QHBoxLayout *hBoxLayout;
    QVBoxLayout *vBoxLayout;

    /* 定时器 */
    QTimer *timer;

    /* 获取本机的网络的信息，返回类型是 QString */
    QString getHostInfo();

private slots:
    /* 定时器槽函数，点击按钮后定时触发 */
    void timerTimeOut();

    /* 显示本机信息 */
    void showHostInfo();

    /* 启动定时器 */
    void timerStart();

    /* 清空 textBrowser 的信息 */
    void clearHostInfo();
};
#endif // MAINWINDOW_H
