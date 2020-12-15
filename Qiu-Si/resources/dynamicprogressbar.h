#ifndef DYNAMICPROGRESSBAR_H
#define DYNAMICPROGRESSBAR_H

#include <QProgressBar>
#include <QPixmap>
#include <QImage>
#include <QPainter>

#include <QStyleOptionProgressBarV2>

class DynamicProgressBar : public QProgressBar
{
    Q_OBJECT
protected slots:
    void  onValueChanged(int value);
public:
    explicit DynamicProgressBar(const QString &fileName = nullptr, QWidget *parent = 0);

    void DrawProgress();

    void paintEvent(QPaintEvent *e);

    //    QPixmap loadPix;
    QImage loadImg;
signals:

};

#endif // DYNAMICPROGRESSBAR_H
