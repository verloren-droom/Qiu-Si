#include "aboutdia.h"

AboutDia::AboutDia(QWidget *parent) : QDialog(parent)
{
    InitDialog();
}

void AboutDia::InitDialog()
{
    // 去掉右上角的问号按钮
    setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint);
    setWindowTitle("Qiu-Si");
    setFixedSize(360, 180);

    QFont aboutFont;
    aboutFont.setPointSize(12);

    // 大标题
    lbl_about = new QLabel(this);
    lbl_about->setGeometry(0, 0, width(), 45);
    lbl_about->setAlignment(Qt::AlignCenter);
    QFont aboutfont;
    aboutfont.setBold(true);
    aboutfont.setPointSize(20);
    lbl_about->setFont(aboutfont);
    lbl_about->setText("Qiu-Si");

    // 项目链接
    lbl_address = new QLabel(this);
    lbl_address->setGeometry(0, 45, width(), 30);
    lbl_address->setAlignment(Qt::AlignCenter);
    lbl_address->setFont(aboutFont);
    lbl_address->setText("<a style='color: green;' href=\"https://github.com/verloren-droom/Qiu-Si\">GitHub源码主页");
    lbl_address->setOpenExternalLinks(true);

    // 作者
    lbl_author = new QLabel(this);
    lbl_author->setGeometry(0, 75, width(), 30);
    lbl_author->setAlignment(Qt::AlignCenter);
    lbl_author->setFont(aboutFont);
    lbl_author->setText("Author: verloren-droom");

    // 邮箱
    lbl_email = new QLabel(this);
    lbl_email->setGeometry(0, 105, width(), 30);
    lbl_email->setAlignment(Qt::AlignCenter);
    lbl_email->setFont(aboutFont);
    lbl_email->setText("Email: hong125841@gmail.com");

    // 设置版本程序信息
    lbl_info = new QLabel(this);
    lbl_info->setGeometry(0, 135, width(), 30);
    lbl_info->setAlignment(Qt::AlignCenter);
    lbl_info->setFont(aboutFont);
    lbl_info->setText("Version 0.0.1 Build 0");

//    setAttribute(Qt::WA_DeleteOnClose);
}
