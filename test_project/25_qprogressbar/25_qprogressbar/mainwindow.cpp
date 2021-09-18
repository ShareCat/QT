#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    /* 设置主窗体位置与大小 */
    this->setGeometry(0, 0, 800, 480);
    progressBar = new QProgressBar(this);
    progressBar->setGeometry(300, 200, 200, 60);

    /*样式表设置，常用使用 setStyleSheet 来设置样式（实现界面美化的功能），具体可参考 styleSheet */
    progressBar->setStyleSheet (
        "QProgressBar{border:8px solid #FFFFFF;"
        "height:30;"
        "border-image:url(:/images/battery.png);" //背景图片
        "text-align:center;" // 文字居中
        "color:rgb(255,0,255);"
        "font:20px;" // 字体大小为 20px
        "border-radius:10px;}"
        "QProgressBar::chunk{"
        "border-radius:5px;" // 斑马线圆角
        "border:1px solid black;" // 黑边，默认无边
        "background-color:skyblue;"
        "width:10px;margin:1px;}" // 宽度和间距
        );

    /* 设置 progressBar 的范围值 */
    progressBar->setRange(0, 100);
    /* 初始化 value 为 0 */
    value = 0;
    /* 给 progressBar 设置当前值 */
    progressBar->setValue(value);
    /* 设置当前文本字符串的显示格式 */
    progressBar->setFormat("Charging%p%");

    /* 定时器实例化设置每 100ms 发送一个 timeout 信号 */
    timer = new QTimer(this);
    timer->start(100);

    /* 信号槽连接 */
    connect(timer, SIGNAL(timeout()), this, SLOT(timerTimeOut()));
}

MainWindow::~MainWindow()
{
}

void MainWindow::timerTimeOut()
{
    /* 定显示器时间到，value 值自加一 */
    value ++;
    progressBar->setValue(value);
    /* 若 value 值大于 100，令 value 再回到 0 */
    if(value>100)
    value = 0;
}
