#ifndef QIUSIMEDIABUTTON_H
#define QIUSIMEDIABUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QShortcut>

#include "qiusimedia.h"

class QiuSiMediaButton : public QWidget
{
    Q_OBJECT
public:
    explicit QiuSiMediaButton(QWidget *parent = nullptr);

    void MediaBtnSet();

private:
    QPushButton *btn_play_pause, *btn_forward, *btn_backward;
    QShortcut *sc_play;

//    QiuSiMedia *qs_media;

    QString SetBtnStyle();
    void PlayBtnSwitch();

signals:

};

#endif // QIUSIMEDIABUTTON_H
