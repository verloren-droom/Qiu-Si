#include "qiusivolumecontrol.h"

QiuSiVolumeControl::QiuSiVolumeControl(const QString &color, QWidget *parent)
    : QWidget(parent)
{
    lbl_volumeImage = new QLabel(this);
    qs_volumeControl = new QiuSiSlider(color, this);
    btn_list = new QToolButton(this);
    playlist = new QiuSiPlaylist(this);

    setFixedSize(135, 80);
    playlist->close();
    btn_list->setToolTip("open Playlist");
    btn_list->setToolTipDuration(1);
    qs_volumeControl->setToolTipDuration(2);

    btn_list->setIcon(QIcon(QPixmap(":icon/images/icon/List_256.png")));
    btn_list->setStyleSheet(QString("QToolButton{"
                                    "border: 0px;}"
                                    "QToolButton::pressed{"
                                    "background-image: url(:icon/images/icon/List_256_click.png);}"));

    QHBoxLayout *lay = new QHBoxLayout;
    lay->addWidget(lbl_volumeImage);
    lay->addWidget(qs_volumeControl);
    lay->addWidget(btn_list);
    lay->setContentsMargins(0, 10, 0, 20);

    lbl_volumeImage->setToolTip(QString("Volume"));

    connect(QiuSiMedia::instance()->musicPlayer, &QMediaPlayer::volumeChanged, this, &QiuSiVolumeControl::ChangeImage);
    connect(qs_volumeControl, &QiuSiSlider::valueChanged, QiuSiMedia::instance()->musicPlayer, [=](int v){
        QiuSiMedia::instance()->musicPlayer->setVolume(v);
        qs_volumeControl->setToolTip(QString("%1").arg(QiuSiMedia::instance()->musicPlayer->volume(), 0, 10));
    });
    connect(qs_volumeControl, &QiuSiSlider::valueChanged, this, &QiuSiVolumeControl::ChangeImage);

    qs_volumeControl->setValue(QiuSiMedia::instance()->musicPlayer->volume());

    setLayout(lay);
}

void QiuSiVolumeControl::ChangeImage(int s)
{
    if (s > 30 && s <= 100)
        lbl_volumeImage->setPixmap(QPixmap(":icon/images/icon/Louder_16.png"));
    else if (s > 0 && s <= 30)
        lbl_volumeImage->setPixmap(QPixmap(":icon/images/icon/Quieter_16.png"));
    else if (s == 0)
        lbl_volumeImage->setPixmap(QPixmap(":icon/images/icon/TurnOff_16.png"));
}

void QiuSiVolumeControl::ShowPlaylist()
{
    connect(btn_list, &QToolButton::clicked, [=]{
        if (playlist->isVisible())
        {
            playlist->close();
            btn_list->setToolTip("open playlist");
        }
        else
        {
            playlist->show();
            btn_list->setToolTip("close playlist");
        }
    });
}
