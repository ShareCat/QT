#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QFile>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    /* 用于读取文件后显示 */
    QTextEdit *textEdit;

    /* QFile 类型对象 */
    QFile file;

    /* 水平布局 */
    QHBoxLayout *hBoxLayout;

    /* 垂直布局 */
    QVBoxLayout *vBoxLayout;

    /* 水平布局 Widget */
    QWidget *hWidget;

    /* 垂直布局 Widget */
    QWidget *vWidget;

    /* 打开文件按钮 */
    QPushButton *openPushButton;

    /* 关闭文件按钮 */
    QPushButton *closePushButton;

private slots:
    /* 打开文本文件 */
    bool openFile();

    /* 关闭文本文件 */
    void closeFile();
};
#endif // MAINWINDOW_H
