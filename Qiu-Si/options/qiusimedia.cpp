#include "qiusimedia.h"

QiuSiMedia::QiuSiMedia(QWidget *parent)
    : QWidget(parent)
    , musicPlayer(new QMediaPlayer(this))
    , musicPlaylist(new QMediaPlaylist(this))
{
    InitMedia();
}

void QiuSiMedia::InputMediaPath(const QString &path)
{
    mediaPath = path;
}

void QiuSiMedia::InitMedia()
{
    musicPlaylist->setPlaybackMode(QMediaPlaylist::Loop);
    musicPlaylist->addMedia(QUrl::fromLocalFile(mediaPath));

    musicPlayer->setPlaylist(musicPlaylist);
}

qint64 QiuSiMedia::MediaTime(const QString &filePath)
{
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly)) {
        qint64 fileSize = file.size() / (16000.0 * 2.0);
        file.close();
        return fileSize;
    }
    return -1;
}
