#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
/* 引入 commandLinkButton */
#include <qcommandlinkbutton.h>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    /* 声明一个 commandLinkButton 对象 */
    QCommandLinkButton *commandLinkButton;

private slots:
    /* 声明 commandLinkButton 对象的槽函数 */
    void commandLinkButtonClicked(int);
};
#endif // MAINWINDOW_H
