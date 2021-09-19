#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QChartView>
#include <QSplineSeries>
#include <QScatterSeries>
#include <QDebug>
#include <QValueAxis>
#include <QTimer>

/* 必需添加命名空间 */
QT_CHARTS_USE_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    /* 接收数据接口 */
    void receivedData(int);

    /* 数据最大个数 */
    int maxSize;

    /* x 轴上的最大值 */
    int maxX;

    /* y 轴上的最大值 */
    int maxY;

    /* y 轴 */
    QValueAxis *axisY;

    /* x 轴 */
    QValueAxis *axisX;

    /* QList int 类型容器 */
    QList<int> data;

    /* QSplineSeries 对象（曲线）*/
    QSplineSeries *splineSeries;

    /* QChart 图表 */
    QChart *chart;

    /* 图表视图 */
    QChartView *chartView;

    /* 定时器 */
    QTimer *timer;

private slots:
    void timerTimeOut();
};
#endif // MAINWINDOW_H
