#include "qiusivolumecontrol.h"

QiuSiVolumeControl::QiuSiVolumeControl(const QString &color, QWidget *parent)
    : QWidget(parent)
    , lbl_volumeImage(new QLabel(this))
    , qs_volumeControl(new QiuSiSlider(color, this))
    , qs_media(new QiuSiMedia(this))
{
    setFixedSize(200, 100);

    QHBoxLayout *lay = new QHBoxLayout;
    lay->addWidget(lbl_volumeImage);
    lay->addWidget(qs_volumeControl);
    lay->setAlignment(Qt::AlignCenter);

    lbl_volumeImage->setPixmap(QPixmap(":icon/images/icon/TurnOff_16.png"));

    connect(qs_media->musicPlayer, &QMediaPlayer::volumeChanged, this, &QiuSiVolumeControl::ChangeImage);
    connect(qs_volumeControl, &QiuSiSlider::valueChanged, qs_media->musicPlayer, &QMediaPlayer::setVolume);
    connect(qs_volumeControl, &QiuSiSlider::valueChanged, this, &QiuSiVolumeControl::ChangeImage);

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
