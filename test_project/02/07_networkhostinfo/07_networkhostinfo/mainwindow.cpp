#include "mainwindow.h"

#include <QNetworkInterface>
#include <QHostInfo>
#include <QThread>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    /* 设置位置与大小 */
    this->setGeometry(0, 0, 800, 480);

    /* 点击获取本地信息按钮和清空文本按钮 */
    pushButton[0] = new QPushButton();
    pushButton[1] = new QPushButton();

    pushButton[0]->setText("获取本机信息");
    pushButton[1]->setText("清空文本信息");

    /* 按钮的大小根据文本自适应，注意 setSizePolicy 需要在布局中使用 */
    pushButton[0]->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    pushButton[1]->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    /* 水平 Widget 和垂直 Widget 用于添加布局 */
    hWidget = new QWidget();
    vWidget = new QWidget();

    /* 水平布局和垂直布局 */
    hBoxLayout = new QHBoxLayout();
    vBoxLayout = new QVBoxLayout();

    /* 文本浏览框 */
    textBrowser = new QTextBrowser();

    /* 添加到水平布局 */
    hBoxLayout->addWidget(pushButton[0]);
    hBoxLayout->addWidget(pushButton[1]);

    /* 将水平布局设置为 hWidget 的布局 */
    hWidget->setLayout(hBoxLayout);

    /* 将文本浏览框和 hWidget 添加到垂直布局 */
    vBoxLayout->addWidget(textBrowser);
    vBoxLayout->addWidget(hWidget);

    /* 将垂直布局设置为 vWidget 的布局 */
    vWidget->setLayout(vBoxLayout);

    /* 设置 vWidget 为中心部件 */
    setCentralWidget(vWidget);

    /* 定时器初始化 */
    timer = new QTimer();

    /* 信号槽连接 */
    connect(pushButton[0], SIGNAL(clicked()), this, SLOT(timerStart()));
    connect(pushButton[1], SIGNAL(clicked()), this, SLOT(clearHostInfo()));
    connect(timer, SIGNAL(timeout()), this, SLOT(timerTimeOut()));
}

MainWindow::~MainWindow()
{
}

void MainWindow::timerStart()
{
    /* 清空文本 */
    textBrowser->clear();

    /* 定时 1s */
    timer->start(1000);
}

void MainWindow::timerTimeOut()
{
    /* 显示本机信息 */
    showHostInfo();

    /* 停止定时器 */
    timer->stop();
}

QString MainWindow::getHostInfo()
{
    /* 通过 QHostInfo 的 localHostName 函数获取主机名称 */
    QString str = "主机名称：" + QHostInfo::localHostName() + "\n";

    /* 获取所有的网络接口，QNetworkInterface 类提供主机的 IP 地址和网络接口的列表 */
    QList<QNetworkInterface> list = QNetworkInterface::allInterfaces();

    /* 遍历 list */
    foreach (QNetworkInterface interface, list) {
        str+= "网卡设备:" + interface.name() + "\n";
        str+= "MAC 地址:" + interface.hardwareAddress() + "\n";

        /* QNetworkAddressEntry 类存储 IP 地址子网掩码和广播地址 */
        QList<QNetworkAddressEntry> entryList = interface.addressEntries();

        /* 遍历 entryList */
        foreach (QNetworkAddressEntry entry, entryList) {
            /* 过滤 IPv6 地址，只留下 IPv4 */
            if (entry.ip().protocol() ==
                QAbstractSocket::IPv4Protocol) {
                str+= "IP 地址:" + entry.ip().toString() + "\n";
                str+= "子网掩码:" + entry.netmask().toString() + "\n";
                str+= "广播地址:" + entry.broadcast().toString() + "\n\n";
            }
        }
    }

    /* 返回网络信息 */
    return str;
}

void MainWindow::showHostInfo()
{
    /* 获取本机信息后显示到 textBrowser */
    textBrowser->insertPlainText(getHostInfo());
}

void MainWindow::clearHostInfo()
{
    /* 判断 textBrowser 是否为空，如果不为空则清空文本 */
    if (!textBrowser->toPlainText().isEmpty())

    /* 清空文本 */
    textBrowser->clear();
}
