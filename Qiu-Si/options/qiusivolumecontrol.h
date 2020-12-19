#ifndef QIUSIVOLUMECONTROL_H
#define QIUSIVOLUMECONTROL_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>

#include "qiusislider.h"

class QiuSiVolumeControl : public QWidget
{
    Q_OBJECT
public:
    explicit QiuSiVolumeControl(const QString &color = "#000000", QWidget *parent = nullptr);

private:
    QLabel *lbl_volumeImage;

    QiuSiSlider *qs_volumeControl;

signals:

};

#endif // QIUSIVOLUMECONTROL_H
