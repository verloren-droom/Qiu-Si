#ifndef QIUSIMEDIA_H
#define QIUSIMEDIA_H

#include <QWidget>
#include <QMediaPlaylist>
#include <QMediaPlayer>
#include <QFile>
#include <QGlobalStatic>

class QiuSiMedia : public QWidget
{
    Q_OBJECT
public:
    explicit QiuSiMedia(QWidget *parent = nullptr);
    static QiuSiMedia *instance();

    void InputMediaPath(const QString &path);
    QString OutputMediaPath();

    QMediaPlayer *musicPlayer;
    QMediaPlaylist *musicPlaylist;

    qint64 MediaTime(const QString &filePath);

private:

    static QString mediaPath;
    void InitMedia();


signals:
    void changePath(QString path);
};

#endif // QIUSIMEDIA_H
