#include "dynamicprogressbar.h"

DynamicProgressBar::DynamicProgressBar(const QString &fileName, QWidget *parent) :
    QProgressBar(parent),
    loadImg(fileName)
{
    setRange(0, 100);
    setValue(20);
    setTextVisible(false);
    setFixedSize(360, 15);

//    onValueChanged(value());
}

void DynamicProgressBar::DrawProgress()
{

}

void DynamicProgressBar::onValueChanged(int value)
{
    QString qss= "QProgressBar{"
               "border: 1px solid rgb(16, 135, 209);"
               "background: rgba(248,248,255,180);"
               "border-radius: 6px; }"
               "QProgressBar::chunk:enabled {"
               "border-radius: 4px; "
               "background: qlineargradient(x1:0, y1:0, x2:1, y2:0";

//    double EndColor = static_cast<double>(maximum()) / maximum();    //获取比例

    for(int i=0; i < 100; ++i)
    {
//        double Current = EndColor * i / 100;
//        QRgb rgb = loadImg.pixel((loadImg.width() - 1)*Current, loadImg.height()/2);
        QRgb rgb = qRgb(192, 44, 56);
        QColor c(rgb);
        qss.append(QString(",stop:%1  rgb(%2,%3,%4)").arg(i / 100.0).arg(c.red()).arg(c.green()).arg(c.blue()));
    }

    qss.append(");}");
    setStyleSheet(qss);

}

void DynamicProgressBar::paintEvent(QPaintEvent *e)
{
    QProgressBar::paintEvent(e);
    QStyleOptionProgressBar opt;
    initStyleOption(&opt);

    if (value() != 0)
    {
        QPainter painter(this);
        QRect rect1 = style()->subElementRect(QStyle::SE_ProgressBarContents, &opt, this);
        //QRectF rect1=this->rect();
        double _width=static_cast<double>(value())/static_cast<double>(value())*rect1.width();
        QLinearGradient gradient(0,0,_width,rect1.height());
        gradient.setColorAt(0,Qt::red);
        gradient.setColorAt(1,Qt::blue);
        painter.setBrush(gradient);
        QRectF rect2=QRectF(rect1.topLeft(),QSize(static_cast<int>(_width),static_cast<int>(rect1.height())));
        rect2.adjust(0,0.8,0,-2);
        painter.drawRoundedRect(rect2, 10, 10);
        //painter.drawRect(rect);
    }

}
