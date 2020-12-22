#include "qiusimedia.h"

Q_GLOBAL_STATIC(QiuSiMedia, qs_media)

QiuSiMedia* QiuSiMedia::instance()
{
    return qs_media;
}

QiuSiMedia::QiuSiMedia(QWidget *parent)
    : QWidget(parent)
    , musicPlayer(new QMediaPlayer(this))
    , musicPlaylist(new QMediaPlaylist(this))
{
    musicPlaylist->setPlaybackMode(QMediaPlaylist::Loop);

}

QString QiuSiMedia::mediaPath = "";

void QiuSiMedia::InputMediaPath(const QString &path)
{
    mediaPath = path;
    emit changePath(mediaPath);
    musicPlaylist->addMedia(QUrl::fromLocalFile(mediaPath));

    musicPlayer->setPlaylist(musicPlaylist);
}

QString QiuSiMedia::OutputMediaPath()
{
    return mediaPath;
}


qint64 QiuSiMedia::MediaTime(const QString &filePath)
{
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly)) {
        qint64 fileSize = file.size() / (16000.0 * 1.0);
        file.close();
        return fileSize;
    }
    return -1;
}
