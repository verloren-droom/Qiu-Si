#ifndef QIUSISLIDER_H
#define QIUSISLIDER_H

#include <QSlider>
#include <QMouseEvent>
#include <QMediaPlayer>

class QiuSiSlider : public QSlider
{
    Q_OBJECT
public:
    explicit QiuSiSlider(const QString &color, QWidget *parent = nullptr);

//    void mousePressEvent(QMouseEvent *ev);
//    void mouseMoveEvent(QMouseEvent *ev);
    QString QiusiSliderStyle(QString bgColor);

private:
    void InitUi();

    QPoint dragPos;

signals:

};

#endif // QIUSISLIDER_H
