#include "qiusivideomode.h"

QiuSiVideoMode::QiuSiVideoMode(const QString &path, QWidget *parent)
    : QWidget(parent)
    , videoPath(path)
{
    Init();
    VideoPlayingFunc(videoPath);
}

void QiuSiVideoMode::Init()
{
    btn_play = new QPushButton(this);
    btn_play->resize(100, 100);
    btn_play->setIcon(QIcon(":icon/images/icon/Play_256x256.png"));
    btn_play->setStyleSheet(SetBtnStyle());

    btn_backward = new QPushButton(QIcon(":icon/images/icon/Backward_378x256.png"), "", this);
    btn_backward->setStyleSheet(SetBtnStyle());

    btn_forward = new QPushButton(QIcon(":icon/images/icon/Forward_378x256.png"), "", this);
    btn_forward->setStyleSheet(SetBtnStyle());

    QHBoxLayout *layh_btn = new QHBoxLayout;
    layh_btn->addWidget(btn_backward);
    layh_btn->addWidget(btn_play);
    layh_btn->addWidget(btn_forward);
//    QVBoxLayout *layv = new QVBoxLayout;
//    layh_btn->addWidget(btn_play);
//    layh_btn->setAlignment(Qt::AlignCenter);
//    layv->addWidget(btn_play);
    layh_btn->setAlignment(Qt::AlignBottom);
    setLayout(layh_btn);
}

void QiuSiVideoMode::SetVideoPath(const QString &path)
{
    videoPath = path;
}

void QiuSiVideoMode::VideoPlayingFunc(QString path)
{
    musicPlayer = new QMediaPlayer(this);
    musicPlaylist = new QMediaPlaylist(this);
    musicPlaylist->setPlaybackMode(QMediaPlaylist::Loop);
    musicPlaylist->addMedia(QUrl::fromLocalFile(path));

    musicPlayer->setPlaylist(musicPlaylist);
    musicPlayer->stop();

    if (path.isEmpty())
        return;
    connect(btn_play, &QPushButton::clicked, [=]{
        switch (musicPlayer->state()) {
        case QMediaPlayer::PlayingState:
            musicPlayer->pause();
            btn_play->setIcon(QIcon(":icon/images/icon/Pause_256x256.png"));
            break;
        case QMediaPlayer::PausedState: case QMediaPlayer::StoppedState:
            musicPlayer->play();
            btn_play->setIcon(QIcon(":icon/images/icon/Play_256x256.png"));
            break;
        }
    });
}

QString QiuSiVideoMode::SetBtnStyle()
{
    return "QPushButton{background-color: white; border-radius: 8px;  border: 1px groove gray; border-style: outset;}"
            "QPushButton:hover{background-color:white;}"
            "QPushButton:pressed{background-color: #c02c38; border-style: inset;}";
}
