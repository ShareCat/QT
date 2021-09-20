#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QUdpSocket>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QTextBrowser>
#include <QLabel>
#include <QComboBox>
#include <QSpinBox>
#include <QHostInfo>
#include <QLineEdit>
#include <QNetworkInterface>
#include <QDebug>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    /* Udp 通信套接字 */
    QUdpSocket *udpSocket;

    /* 按钮 */
    QPushButton *pushButton[5];
    /* 标签文本 */
    QLabel *label[3];

    /* 水平容器 */
    QWidget *hWidget[3];

    /* 水平布局 */
    QHBoxLayout *hBoxLayout[3];

    /* 垂直容器 */
    QWidget *vWidget;

    /* 垂直布局 */
    QVBoxLayout *vBoxLayout;

    /* 文本浏览框 */
    QTextBrowser *textBrowser;

    /* 用于显示本地 ip */
    QComboBox *comboBox;

    /* 用于选择端口 */
    QSpinBox *spinBox[2];

    /* 文本输入框 */
    QLineEdit *lineEdit;

    /* 存储本地的 ip 列表地址 */
    QList<QHostAddress> IPlist;

    /* 获取本地的所有 ip */
    void getLocalHostIP();

    private slots:
    /* 绑定端口 */
    void bindPort();

    /* 解绑端口 */
    void unbindPort();

    /* 清除文本框时的内容 */
    void clearTextBrowser();

    /* 接收到消息 */
    void receiveMessages();

    /* 发送消息 */
    void sendMessages();

    /* 广播消息 */
    void sendBroadcastMessages();

    /* 连接状态改变槽函数 */
    void socketStateChange(QAbstractSocket::SocketState);
};
#endif // MAINWINDOW_H
