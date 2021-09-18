#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

/* 引入 QComboBox */
#include <QComboBox>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    /* 声明一个 QComboBox 对象 */
    QComboBox *comboBox;

private slots:
    /* 声明信号槽 */
    void comboBoxIndexChanged(int);
};
#endif // MAINWINDOW_H
