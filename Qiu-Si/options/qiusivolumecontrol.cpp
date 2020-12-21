#include "qiusivolumecontrol.h"

QiuSiVolumeControl::QiuSiVolumeControl(const QString &color, QWidget *parent)
    : QWidget(parent)
    , lbl_volumeImage(new QLabel(this))
    , qs_volumeControl(new QiuSiSlider(color, this))
    , qs_media(new QiuSiMedia(this))
{
    setFixedSize(120, 80);

    QHBoxLayout *lay = new QHBoxLayout;
    lay->addWidget(lbl_volumeImage);
    lay->addWidget(qs_volumeControl);
    lay->setContentsMargins(0, 10, 0, 20);

    connect(QiuSiMedia::instance()->musicPlayer, &QMediaPlayer::volumeChanged, this, &QiuSiVolumeControl::ChangeImage);
    connect(qs_volumeControl, &QiuSiSlider::valueChanged, QiuSiMedia::instance()->musicPlayer, &QMediaPlayer::setVolume);
    connect(qs_volumeControl, &QiuSiSlider::valueChanged, this, &QiuSiVolumeControl::ChangeImage);

    qs_volumeControl->setValue(QiuSiMedia::instance()->musicPlayer->volume());

    setLayout(lay);
}

void QiuSiVolumeControl::ChangeImage(int s)
{
    if (s >= 60)
        lbl_volumeImage->setPixmap(QPixmap(":icon/images/icon/Louder_16.png"));
    else if (s >= 30)
        lbl_volumeImage->setPixmap(QPixmap(":icon/images/icon/Quieter_16.png"));
    else if (s == 0)
        lbl_volumeImage->setPixmap(QPixmap(":icon/images/icon/TurnOff_16.png"));
}
