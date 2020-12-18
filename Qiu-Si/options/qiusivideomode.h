#ifndef QIUSIVIDEOMODE_H
#define QIUSIVIDEOMODE_H

#include <QWidget>
#include <QMessageBox>
#include <QMediaPlayer>
#include <QPushButton>
#include <QMediaPlaylist>
#include <QUrl>
#include <QHBoxLayout>
#include <QVBoxLayout>

class QiuSiVideoMode : public QWidget
{
    Q_OBJECT
public:
    explicit QiuSiVideoMode(const QString &path = nullptr, QWidget *parent = nullptr);

    void VideoPlayingFunc(QString path);

    QString SetBtnStyle();
    void SetVideoPath(const QString &path);
private:
    void Init();

    QPushButton *btn_play, *btn_forward, *btn_backward;

    QMediaPlayer *musicPlayer;
    QMediaPlaylist *musicPlaylist;

    QString videoPath;

signals:

};

#endif // QIUSIVIDEOMODE_H
