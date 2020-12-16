#include "imagewindow.h"

ImageWindow::ImageWindow(const QString &filePath, QWidget *parent)
    : QDialog(parent)
    , pix_res(filePath)
{
    Init();
}

void ImageWindow::Init()
{
    // 去掉对话框的问号，和背景透明
    setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint/* | Qt::Dialog | Qt::FramelessWindowHint*/);
    setAttribute(Qt::WA_TranslucentBackground);
    setBackgroundRole(QPalette::Background);

    lbl_main = new QLabel(this);
    lbl_main->setPixmap(pix_res);
    lbl_main->setAlignment(Qt::AlignCenter);
    resize(pix_res.size());
    setMinimumSize(pix_res.size());
    lbl_main->resize(size());
    QShortcut *sc_windowClose = new QShortcut(QKeySequence("Q"), this);
    connect(sc_windowClose, &QShortcut::activated, [=]{this->close();});
}

void ImageWindow::mousePressEvent(QMouseEvent *ev)
{
    // 移动后部件所在的位置
    this->dPos = ev->globalPos() - this->pos();
}

void ImageWindow::mouseMoveEvent(QMouseEvent *ev)
{
    // 移动位置
    move(ev->globalPos() - dPos);
}

void ImageWindow::hoverEvent(QHoverEvent *)
{
    lbl_info = new QLabel(this);
    lbl_info->setText(QString("width: %1\nheight: %2").arg(pix_res.width()).arg(height()));
}
