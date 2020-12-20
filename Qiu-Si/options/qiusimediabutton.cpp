#include "qiusimediabutton.h"

QiuSiMediaButton::QiuSiMediaButton(QWidget *parent): QWidget(parent)
{
    setFixedSize(500, 90);

    // Backword button
    btn_backward = new QPushButton(this);
    btn_backward->setIcon(QIcon(":icon/images/icon/Backward_378x256.png"));
    btn_backward->setStyleSheet(SetBtnStyle() + "QPushButton:pressed{border-image: url(:icon/images/icon/Backward_256_click.png);}");

    // Play and pause button
    btn_play_pause = new QPushButton(this);
    btn_play_pause->setIcon(QIcon(":icon/images/icon/Play_256x256.png"));
    btn_play_pause->setStyleSheet(SetBtnStyle() + "QPushButton:pressed{border-image: url(:icon/images/icon/Play_256_click.png);}");

    // Forward button
    btn_forward = new QPushButton(this);
    btn_forward->setIcon(QIcon(":icon/images/icon/Forward_378x256.png"));
    btn_forward->setStyleSheet(SetBtnStyle() + "QPushButton:pressed{border-image: url(:icon/images/icon/Forward_256_click.png);}");

    QHBoxLayout *layh_btn = new QHBoxLayout;
    layh_btn->addWidget(btn_backward);
    layh_btn->addWidget(btn_play_pause);
    layh_btn->addWidget(btn_forward);
    layh_btn->setAlignment(Qt::AlignCenter);

    MediaBtnSet();
}

QString QiuSiMediaButton::SetBtnStyle()
{
    return "QPushButton{"
           "background-color: white; border: 0px; border-style: outset;"
           "}"
           "QPushButton:hover{"
           "background-color: white;"
           "}"
           "QPushButton:pressed{"
           "border-style: inset;}";
}

// Media button function
void QiuSiMediaButton::MediaBtnSet()
{
    qs_media = new QiuSiMedia(this);

    if (qs_media->mediaPath.isEmpty())
        return;
    connect(btn_play_pause, &QPushButton::clicked, [=]{
        switch (qs_media->musicPlayer->state()) {
        case QMediaPlayer::PlayingState:
            qs_media->musicPlayer->pause();
            btn_play_pause->setIcon(QIcon(":icon/images/icon/Play_256x256.png"));
            break;
        case QMediaPlayer::PausedState: case QMediaPlayer::StoppedState:
            qs_media->musicPlayer->play();
            btn_play_pause->setIcon(QIcon(":icon/images/icon/Pause_256x256.png"));
            break;
        }
    });
}
