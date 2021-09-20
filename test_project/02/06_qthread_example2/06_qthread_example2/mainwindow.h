#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QThread>
#include <QDebug>
#include <QPushButton>
#include <QMutexLocker>
#include <QMutex>

/* 工人类 */
class Worker;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    /* 开始线程按钮 */
    QPushButton *pushButton1;

    /* 打断线程按钮 */
    QPushButton *pushButton2;

    /* 全局线程 */
    QThread workerThread;

    /* 工人类 */
    Worker *worker;

private slots:
    /* 按钮 1 点击开启线程 */
    void pushButton1Clicked();

    /* 按钮 2 点击打断线程 */
    void pushButton2Clicked();

    /* 用于接收工人是否在工作的信号 */
    void handleResults(const QString &);

signals:
    /* 工人开始工作（做些耗时的操作 ） */
    void startWork(const QString &);
};

/* Worker 类，这个类声明了 doWork1 函数，将整个 Worker 类移至线程 workerThread */
class Worker : public QObject
{
    Q_OBJECT

    private:
    /* 互斥锁 */
    QMutex lock;

    /* 标志位 */
    bool isCanRun;

    public slots:
    /* 耗时的工作都放在槽函数下，工人可以有多份不同的工作，但是每次只能去做一份 */
    void doWork1(const QString &parameter) {

        /* 标志位为真 */
        isCanRun = true;

        qDebug()<<"doWork1"<<endl;
        /* 死循环 */
        while (1) {
            /* 此{}作用是 QMutexLocker 与 lock 的作用范围，获取锁后，运行完成后即解锁 */
            {
                QMutexLocker locker(&lock);
                /* 如果标志位不为真 */
                if (!isCanRun) {
                    /* 跳出循环 */
                    break;
                }
            }
            /* 使用 QThread 里的延时函数，当作一个普通延时 */
            QThread::sleep(2);

            emit resultReady(parameter + "doWork1 函数");
        }
        /* doWork1 运行完成，发送信号 */
        emit resultReady("打断 doWork1 函数");
    }

    // void doWork2();...

    public:
    /* 打断线程（注意此方法不能放在槽函数下） */
    void stopWork() {
        qDebug()<<"打断线程"<<endl;

        /* 获取锁后，运行完成后即解锁 */
        QMutexLocker locker(&lock);
        isCanRun = false;
    }

    signals:
    /* 工人工作函数状态的信号 */
    void resultReady(const QString &result);
};
#endif // MAINWINDOW_H
