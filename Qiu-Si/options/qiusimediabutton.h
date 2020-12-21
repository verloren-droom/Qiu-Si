#ifndef QIUSIMEDIABUTTON_H
#define QIUSIMEDIABUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QGridLayout>

#include "qiusimedia.h"

class QiuSiMediaButton : public QWidget
{
    Q_OBJECT
public:
    explicit QiuSiMediaButton(QWidget *parent = nullptr);

    void MediaBtnSet();

private:
    QPushButton *btn_play_pause, *btn_forward, *btn_backward;

//    QiuSiMedia *qs_media;

    QString SetBtnStyle();

signals:

};

#endif // QIUSIMEDIABUTTON_H
