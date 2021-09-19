#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QRadioButton>
#include <QGroupBox>
#include <QVBoxLayout>

class MainWindow : public QMainWindow
{
    Q_OBJECT

#define RADIOBUTTON_COUNT   3

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    /* 声明对象 */
    QGroupBox *groupBox;
    QVBoxLayout *vBoxLayout;
    QRadioButton *radioButton[RADIOBUTTON_COUNT];
};
#endif // MAINWINDOW_H
