#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QThread>
#include <QDebug>
#include <QPushButton>

/* 使用下面声明的 WorkerThread 线程类 */
class WorkerThread;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    /* 在 MainWindow 类里声明对象 */
    WorkerThread *workerThread;

    /* 声明一个按钮，使用此按钮点击后开启线程 */
    QPushButton *pushButton;

    private slots:
    /* 槽函数，用于接收线程发送的信号 */
    void handleResults(const QString &result);

    /* 点击按钮开启线程 */
    void pushButtonClicked();
};

/* 新建一个 WorkerThread 类继承于 QThread */
class WorkerThread : public QThread
{
    /* 用到信号槽即需要此宏定义 */
    Q_OBJECT

    public:
    WorkerThread(QWidget *parent = nullptr) {
        Q_UNUSED(parent);
    }

    /* 重写 run 方法，继承 QThread 的类，只有 run 方法是在新的线程里 */
    void run() override {
        QString result = "线程开启成功";
        // 延时 2s，把延时 2s 当作耗时操作
        sleep(2);

        /* 发送结果准备好的信号 */
        emit resultReady(result);
    }

signals:
    /* 声明一个信号，译结果准确好的信号 */
    void resultReady(const QString &s);
};

#endif // MAINWINDOW_H
