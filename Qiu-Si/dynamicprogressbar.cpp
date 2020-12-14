#include "dynamicprogressbar.h"

DynamicProgressBar::DynamicProgressBar(const QString &fileName, QWidget *parent) :
    QProgressBar(parent),
    loadImg(fileName)
{
    setRange(0, 100);
    setValue(20);
    setTextVisible(false);
    setFixedSize(360, 15);

    onValueChanged(value());
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
