#include "mainwindow.h"

/* 引入桌面服务，用来打开系统文件夹对话框 */
#include <QDesktopServices>
/* 引入 QUrl */
#include <QUrl>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    /* 主窗体设置位置和显示的大小 */
    this->setGeometry(0, 0, 800, 480);

    /* 实例化对象 */
    commandLinkButton = new QCommandLinkButton("打开/home 目录", "点击此将调用系统的窗口打开/home 目录",this);

    /* 设置 QCommandLinkButton 位置和显示大小 */
    commandLinkButton->setGeometry(300, 200, 250, 60);

    /* 信号槽连接 */
    connect(commandLinkButton, SIGNAL(clicked()), this,
    SLOT(commandLinkButtonClicked()));
}

void MainWindow::commandLinkButtonClicked(int a)
{
    /* 调用系统服务打开/home 目录 */
    QDesktopServices::openUrl(QUrl("file:////home/") );
}

MainWindow::~MainWindow()
{
}



