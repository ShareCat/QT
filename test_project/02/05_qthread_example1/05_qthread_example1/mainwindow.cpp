#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    /* 设置位置与大小 */
    this->setGeometry(0, 0, 800, 480);
    /* 对象实例化 */
    pushButton = new QPushButton(this);
    workerThread = new WorkerThread(this);

    /* 按钮设置大小与文本 */
    pushButton->resize(100, 40);
    pushButton->setText("开启线程");

    /* 信号槽连接 */
    connect(workerThread, SIGNAL(resultReady(QString)), this, SLOT(handleResults(QString)));
    connect(pushButton, SIGNAL(clicked()), this, SLOT(pushButtonClicked()));
}

/* 在 MainWindow 的析构函数里退出线程，然后判断线程是否退出成功。因为
我们这个线程是没有循环操作的，直接点击按钮开启线程后，做了 2s 延时操作后就完成了。所
以我们在析构函数里直接退出没有关系 */
MainWindow::~MainWindow()
{
    /* 进程退出，注意本例 run()方法没写循环，此方法需要有循环才生效 */
    workerThread->quit();

    /* 阻塞等待 2000ms 检查一次进程是否已经退出 */
    if (workerThread->wait(2000)) {
        qDebug()<<"线程已经结束！"<<endl;
    }
}

void MainWindow::handleResults(const QString &result)
{
    /* 打印出线程发送过来的结果 */
    qDebug()<<result<<endl;
}

/* 按钮点击后开启线程，首先我们得判断这个线程是否在运行，如果不在运行
我们则开始线程，开始线程用 start()方法，它会调用重写的 run()函数的 */
void MainWindow::pushButtonClicked()
{
    /* 检查线程是否在运行，如果没有则开始运行 */
    if (!workerThread->isRunning())
        workerThread->start();
}
