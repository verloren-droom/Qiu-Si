#include "qiusivolumecontrol.h"

QiuSiVolumeControl::QiuSiVolumeControl(const QString &color, QWidget *parent) : QWidget(parent)
{
    setFixedSize(200, 100);
    lbl_volumeImage = new QLabel(this);
    qs_volumeControl = new QiuSiSlider(color, this);

    QHBoxLayout *lay = new QHBoxLayout;
    lay->addWidget(lbl_volumeImage);
    lay->addWidget(qs_volumeControl);
    lay->setAlignment(Qt::AlignCenter);

    if (qs_volumeControl->value() < 0)
        lbl_volumeImage->setPixmap(QPixmap(":icon/images/icon/Quieter_16.png"));

    setLayout(lay);
}
