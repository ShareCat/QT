#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    /* 设置主窗体位置与大小 */
    this->setGeometry(0, 0, 800, 480);
    /* 以标题为“QGroupBox 示例”实例化 groupBox 对象 */
    groupBox = new QGroupBox(tr("QGroupBox 示例"), this);
    groupBox->setGeometry(300, 100, 300, 200);

    vBoxLayout = new QVBoxLayout();

    /* 字符串链表 */
    QList <QString>list;
    list<<"选项一"<<"选项二"<<"选项三";
    for(int i = 0; i < RADIOBUTTON_COUNT; i++) {
        radioButton[i] = new QRadioButton();
        radioButton[i]->setText(list[i]);
        /* 在 vBoxLayout 添加 radioButton */
        vBoxLayout->addWidget(radioButton[i]);
    }
    /* 添加一个伸缩量 1 */
    vBoxLayout->addStretch(1);
    /* vBoxLayout 布局设置为 groupBox 布局 */
    groupBox->setLayout(vBoxLayout);
}

MainWindow::~MainWindow()
{
}

