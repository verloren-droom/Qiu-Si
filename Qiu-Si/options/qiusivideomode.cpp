#include "qiusivideomode.h"

QiuSiVideoMode::QiuSiVideoMode(QWidget *parent, const QString &path, const QString &color)
    : QWidget(parent)
    , mediaPath(path)
{
    QFileInfo info(mediaPath);
    QString title(info.baseName());
    if (title.isEmpty())
        title = "Unknown music";
    qs_media = new QiuSiMedia(this);
    mediaInfo = new QiuSiStatusInfo(title, ":icon/images/icon/music_64.png", this);
    qs_mediaBtn = new QiuSiMediaButton(this);
    qs_slider = new QiuSiSlider(color, this);
    qs_volume = new QiuSiVolumeControl(color, this);
    qs_media->InputMediaPath(mediaPath);

    mediaInfo->show();
    qs_mediaBtn->show();


    if (mediaPath.isEmpty())
        qs_slider->setEnabled(false);
//    qs_slider->setFixedWidth(400);
    MediaWidgetLayout();
}

void QiuSiVideoMode::MediaWidgetLayout()
{
    qDebug() << "at this";

    QHBoxLayout *lay_overall = new QHBoxLayout;
    lay_overall->addWidget(mediaInfo);

    QVBoxLayout *lay_mid = new QVBoxLayout;
    lay_mid->addWidget(qs_mediaBtn);
    lay_mid->addWidget(qs_slider);
//    lay_mid->setAlignment(Qt::AlignCenter);
    lay_mid->setContentsMargins(10, 0, 0, 10);

    lay_overall->addLayout(lay_mid);
    lay_overall->addWidget(qs_volume);
    lay_overall->setAlignment(Qt::AlignVCenter);

    setLayout(lay_overall);
}

QString QiuSiVideoMode::SetVideoPath(QString path)
{
    mediaPath = path;
    return mediaPath;
}

