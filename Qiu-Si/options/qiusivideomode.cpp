#include "qiusivideomode.h"

QiuSiVideoMode::QiuSiVideoMode(const QString &color, const QString &path, QWidget *parent)
    : QWidget(parent)
    , videoPath(path)
{
    InitUi(color);
}

// Initialize the UI function
void QiuSiVideoMode::InitUi(QString color)
{

    // Play and pause button
    btn_play = new QPushButton(QIcon(":icon/images/icon/Play_256x256.png"), nullptr,this);
    btn_play->setStyleSheet(SetBtnStyle() + "QPushButton:pressed{border-image: url(:icon/images/icon/Play_256_click.png);}");

    // Backword button
    btn_backward = new QPushButton(QIcon(":icon/images/icon/Backward_378x256.png"), nullptr, this);
    btn_backward->setStyleSheet(SetBtnStyle() + "QPushButton:pressed{border-image: url(:icon/images/icon/Backward_256_click.png);}");

    // Forward button
    btn_forward = new QPushButton(QIcon(":icon/images/icon/Forward_378x256.png"), nullptr, this);
    btn_forward->setStyleSheet(SetBtnStyle() + "QPushButton:pressed{border-image: url(:icon/images/icon/Forward_256_click.png);}");

    QHBoxLayout *layh_btn = new QHBoxLayout;
    layh_btn->addWidget(btn_backward);
    layh_btn->addWidget(btn_play);
    layh_btn->addWidget(btn_forward);
    layh_btn->setAlignment(Qt::AlignCenter);
//    layh_btn->setContentsMargins(10, 10, 10, 10);

    InitMusicPlay();
    MusicPlayBtn();

    qs_music = new QiuSiSlider(color, this);
    qs_music->show();
    if (videoPath.isNull())
        qs_music->setEnabled(false);

    QVBoxLayout *layv = new QVBoxLayout;
    layv->addLayout(layh_btn);
    layv->addWidget(qs_music);

    setLayout(layv);
}

void QiuSiVideoMode::InitMusicPlay()
{
    musicPlayer = new QMediaPlayer(this);
    musicPlaylist = new QMediaPlaylist(this);
    musicPlaylist->setPlaybackMode(QMediaPlaylist::Loop);
    musicPlaylist->addMedia(QUrl::fromLocalFile(videoPath));

    musicPlayer->setPlaylist(musicPlaylist);

}

// Music play pause button function
void QiuSiVideoMode::MusicPlayBtn()
{
    if (videoPath.isEmpty())
        return;
    connect(btn_play, &QPushButton::clicked, [=]{
        switch (musicPlayer->state()) {
        case QMediaPlayer::PlayingState:
            musicPlayer->pause();
            btn_play->setIcon(QIcon(":icon/images/icon/Play_256x256.png"));
            break;
        case QMediaPlayer::PausedState: case QMediaPlayer::StoppedState:
            musicPlayer->play();
            btn_play->setIcon(QIcon(":icon/images/icon/Pause_256x256.png"));
            break;
        }
    });

    qs_music->setRange(0, MusicTime(videoPath));
    connect(musicPlayer, &QMediaPlayer::durationChanged, qs_music, &QiuSiSlider::setValue);
    connect(qs_music, &QiuSiSlider::valueChanged, musicPlayer, &QMediaPlayer::setPosition);
}

// Music volume control function
//void QiuSiVideoMode::MusicVolumeControl()
//{
//    qs_volume->setRange(0, 100);
//    connect(musicPlayer, &QMediaPlayer::volumeChanged, qs_volume, &QiuSiSlider::setValue);
//    connect(qs_volume, &QiuSiSlider::valueChanged, musicPlayer, &QMediaPlayer::setVolume);
//}

void QiuSiVideoMode::SetVideoPath(const QString &path)
{
    videoPath = path;
}

QString QiuSiVideoMode::SetBtnStyle()
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

qint64 QiuSiVideoMode::MusicTime(const QString &filePath)
{
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly)) {
        qint64 fileSize = file.size() / (16000.0 * 2.0);
        file.close();
        return fileSize;
    }
    return -1;
}

void QiuSiVideoMode::OnMetaDataAvailableChanged(bool available)
{
    if (available){
        qint64 time = musicPlayer->metaData("Duration").toInt();
        if (time != 0)
//            ui->btn_original_sound->setTotalTime(time / 1000.0);
            return;
    }
}
