#include "qiusivideomode.h"

QiuSiVideoMode::QiuSiVideoMode(QWidget *parent, const QString &color)
    : QWidget(parent)
{
    qs_mediaBtn = new QiuSiMediaButton(this);
    qs_slider = new QiuSiSlider(color, this);

    setFixedSize(500, 80);

    if (QiuSiMedia::instance()->OutputMediaPath().isEmpty())
        qs_slider->setEnabled(false);
//    qs_slider->setFixedWidth(400);


    MediaWidgetLayout();
}

void QiuSiVideoMode::MediaWidgetLayout()
{
    QVBoxLayout *lay_mid = new QVBoxLayout;
    lay_mid->addWidget(qs_mediaBtn);
    lay_mid->addStretch();
    lay_mid->addWidget(qs_slider);
    lay_mid->setAlignment(Qt::AlignHCenter);
//    lay_mid->setContentsMargins(10, 0, 0, 10);

    setLayout(lay_mid);
}

void QiuSiVideoMode::RunSliderBtn()
{
    qs_slider->setEnabled(true);
    qs_mediaBtn->MediaBtnSet();
//    qs_slider->setRange(0, QiuSiMedia::instance()->MediaTime(QiuSiMedia::instance()->OutputMediaPath()));
    connect(qs_slider, &QiuSiSlider::sliderMoved, QiuSiMedia::instance()->musicPlayer, &QMediaPlayer::setPosition);
    connect(QiuSiMedia::instance()->musicPlayer, &QMediaPlayer::durationChanged, [=](int max){
       qs_slider->setRange(0, max);
    });
    connect(QiuSiMedia::instance()->musicPlayer, &QMediaPlayer::positionChanged, qs_slider, &QiuSiSlider::setValue);
}


