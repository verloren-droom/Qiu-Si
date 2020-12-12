#include "qiusi.h"
#include "ui_qiusi.h"

QiuSi::QiuSi(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QiuSi)
{
    InitUi();
    ConnectFunc();
}

void QiuSi::InitUi()
{
    ui->setupUi(this);

    // 设置中心控件
    txt_content = new QTextEdit(this);
    setCentralWidget(txt_content);
//    QHBoxLayout *lay_full = new QHBoxLayout(this);
//    lay_full->addWidget(txt_content);
//    lay_full->setContentsMargins(0, 0, 0, 0);
    txt_content->setReadOnly(true);

    //对话框
    aboutDia = new QDialog;
    aboutDia->setFixedSize(300, 120);
    aboutDia->setWindowTitle("About me");

    // 菜单栏
    mainMenu = menuBar();
    setMenuBar(mainMenu);

    // 文件菜单
    fileMenu = mainMenu->addMenu("File");
    quitAction = fileMenu->addAction("Quit");

    // 帮助菜单
    helpMenu = mainMenu->addMenu("Help");
    aboutAction = helpMenu->addAction("About");

}

void QiuSi::ConnectFunc()
{
    connect(quitAction, &QAction::triggered, [=]{
        close();
    });
    connect(aboutAction, &QAction::triggered, [=]{
        QMessageBox::about(this, "About", "");
        aboutDia->open();
    });
}

QFont QiuSi::UnifiedFont()
{
    QFont font;
    font.setPointSize(14);
    font.setBold(true);
    return font;
}

QiuSi::~QiuSi()
{
    delete ui;
}

