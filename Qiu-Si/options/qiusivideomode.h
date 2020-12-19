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
#include <QSpacerItem>
#include <QLabel>

#include "qiusislider.h"

#include <QDebug>

class QiuSiVideoMode : public QWidget
{
    Q_OBJECT
public:
    explicit QiuSiVideoMode(const QString &color = "#000000", const QString &path = nullptr, QWidget *parent = nullptr);

    void MusicPlayBtn();

//    void MusicVolumeControl();

    void SetVideoPath(const QString &path);
    QString SetBtnStyle();
    qint64 MusicTime(const QString &filePath);

public slots:
    void OnMetaDataAvailableChanged(bool available);
private:
    void InitUi(QString color);
    void InitMusicPlay();

    QPushButton *btn_play, *btn_forward, *btn_backward;

    QMediaPlayer *musicPlayer;
    QMediaPlaylist *musicPlaylist;
    QiuSiSlider *qs_music, *qs_volume;

    QString videoPath;

signals:

};

#endif // QIUSIVIDEOMODE_H
