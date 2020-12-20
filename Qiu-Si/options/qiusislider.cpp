#include "qiusislider.h"

QiuSiSlider::QiuSiSlider(const QString &color, QWidget *parent) : QSlider(parent)
{
    InitUi();
    setStyleSheet(QiusiSliderStyle(color));
}
void QiuSiSlider::InitUi()
{
//    setFixedHeight(40);
    setAttribute(Qt::WA_TranslucentBackground);

    setOrientation(Qt::Horizontal);

}

QString QiuSiSlider::QiusiSliderStyle(QString bgColor)
{
    return QString(
                "QSlider::groove:horizontal{"
                "border: 1px solid %1; height: 1px; margin: 0px 0; left: 5px; right: 5px;"
                "}"
                "QSlider::handle:horizontal{"
                "border: 0px; border-image: url(%2); width: 20px; margin: -8px -8px -8px -10px;"
                "}"
                "QSlider::sub-page:horizontal{"
                "background: %1;"
                "}"
                ).arg(bgColor).arg(":icon/images/icon/maple_1024x1024.png");
}

//void QiuSiSlider::mousePressEvent(QMouseEvent *ev)
//{
//    if (ev->button() == Qt::LeftButton)
//    {
//        dragPos = ev->globalPos() - frameGeometry().topLeft();
//        ev->accept();
//    }
//}

//void QiuSiSlider::mouseMoveEvent(QMouseEvent *ev)
//{
//    if (ev->buttons() == Qt::LeftButton)
//    {
//        move(ev->globalPos() - dragPos);
//        ev->accept();
//    }
//}
