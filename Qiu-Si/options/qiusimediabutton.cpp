#include "qiusimediabutton.h"

QiuSiMediaButton::QiuSiMediaButton(QWidget *parent): QWidget(parent)
{
    // Backword button
    btn_backward = new QPushButton(this);
    btn_backward->setIcon(QIcon(":icon/images/icon/Backward_378x256.png"));
    btn_backward->setStyleSheet(SetBtnStyle() + "QPushButton:pressed{border-image: url(:icon/images/icon/Backward_256_click.png);}");
    btn_backward->setAttribute(Qt::WA_TranslucentBackground);

    // Play and pause button
    btn_play_pause = new QPushButton(this);
    btn_play_pause->setIcon(QIcon(":icon/images/icon/Play_256x256.png"));
    btn_play_pause->setStyleSheet(SetBtnStyle() + "QPushButton:pressed{border-image: url(:icon/images/icon/Play_256_click.png);}");
    btn_play_pause->setAttribute(Qt::WA_TranslucentBackground);

    // Forward button
    btn_forward = new QPushButton(this);
    btn_forward->setIcon(QIcon(":icon/images/icon/Forward_378x256.png"));
    btn_forward->setStyleSheet(SetBtnStyle() + "QPushButton:pressed{border-image: url(:icon/images/icon/Forward_256_click.png);}");
    btn_forward->setAttribute(Qt::WA_TranslucentBackground);

    QHBoxLayout *layh_btn = new QHBoxLayout;
    layh_btn->addStretch();
    layh_btn->addWidget(btn_backward);
    layh_btn->addStretch();
    layh_btn->addWidget(btn_play_pause);
    layh_btn->addStretch();
    layh_btn->addWidget(btn_forward);
    layh_btn->addStretch();

    layh_btn->setContentsMargins(40, 8, 40, 0);

    setLayout(layh_btn);
//    layh_btn->setAlignment(Qt::AlignCenter);
//    layh_btn->setContentsMargins(0, 10, 10, 10);

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
//    qs_media = new QiuSiMedia(this);

    if (QiuSiMedia::instance()->OutputMediaPath().isEmpty())
        return;
    connect(btn_play_pause, &QPushButton::clicked, [=]{
        switch (QiuSiMedia::instance()->musicPlayer->state()) {
        case QMediaPlayer::PlayingState:
            QiuSiMedia::instance()->musicPlayer->pause();
            btn_play_pause->setIcon(QIcon(":icon/images/icon/Play_256x256.png"));
            break;
        case QMediaPlayer::PausedState: case QMediaPlayer::StoppedState:
            QiuSiMedia::instance()->musicPlayer->play();
            btn_play_pause->setIcon(QIcon(":icon/images/icon/Pause_256x256.png"));
            break;
        }
    });

}
