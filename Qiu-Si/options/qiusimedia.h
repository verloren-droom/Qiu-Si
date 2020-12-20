#ifndef QIUSIMEDIA_H
#define QIUSIMEDIA_H

#include <QWidget>
#include <QMediaPlaylist>
#include <QMediaPlayer>
#include <QFile>

class QiuSiMedia : public QWidget
{
    Q_OBJECT
public:
    explicit QiuSiMedia(QWidget *parent = nullptr);

    void InputMediaPath(const QString &path);
    QString mediaPath;

    QMediaPlayer *musicPlayer;
    QMediaPlaylist *musicPlaylist;

    qint64 MediaTime(const QString &filePath);

private:

    void InitMedia();


signals:

};

#endif // QIUSIMEDIA_H
