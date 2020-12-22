#include "qiusivideomode.h"

QiuSiVideoMode::QiuSiVideoMode(QWidget *parent, const QString &color)
    : QWidget(parent)
{
    qs_mediaBtn = new QiuSiMediaButton(this);
    qs_slider = new QiuSiSlider(color, this);
    lbl_now = new QLabel("00:00:00", this);
    QFont font;
    font.setPointSize(8);
    lbl_now->setFont(font);
    lbl_now->setAlignment(Qt::AlignRight | Qt::AlignBottom);
    lbl_now->setContentsMargins(0, 0, 0, 10);
    lbl_end = new QLabel("00:00:00", this);
    lbl_end->setFont(font);
    lbl_end->setAlignment(Qt::AlignBottom | Qt::AlignLeft);
    lbl_end->setContentsMargins(0, 0, 0, 10);

    setFixedSize(550, 80);

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
//    lay_mid->setAlignment(Qt::AlignCenter);
    lay_mid->setContentsMargins(10, 0, 0, 6);

    QHBoxLayout *lay_all = new QHBoxLayout;
    lay_all->addWidget(lbl_now);
    lay_all->addLayout(lay_mid);
    lay_all->addWidget(lbl_end);

    setLayout(lay_all);
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

// Change show time function
void QiuSiVideoMode::ChangeShowTime()
{
    qint64 time = QiuSiMedia::instance()->MediaTime(QiuSiMedia::instance()->OutputMediaPath());

    lbl_end->setText(QString("%1:%2:%3").arg(time / 60 / 60, 2, 10, QChar('0')).arg(time / 60 % 60, 2, 10, QChar('0')).arg(time % 60 % 60, 2, 10, QChar('0')));

//    connect(qs_slider, &QiuSiSlider::valueChanged, [=](int i){
//        lbl_now->setText(QString("%1:%2").arg(QString::number(i / 1000 / 60 % 60)).arg(QString::number(i / 1000 % 60 % 60)));
//    });
    connect(QiuSiMedia::instance()->musicPlayer, &QMediaPlayer::positionChanged, [=](int i){
       lbl_now->setText(QString("%1:%2:%3").arg(i / 1000 / 60 / 60, 2, 10, QChar('0')).arg(i / 1000 / 60 % 60, 2, 10, QChar('0')).arg(i / 1000 % 60 % 60, 2, 10, QChar('0')));
    });

}


