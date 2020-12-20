#ifndef QIUSIVIDEOMODE_H
#define QIUSIVIDEOMODE_H

#include <QWidget>
#include <QMessageBox>
#include <QFileInfo>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSpacerItem>

#include "qiusimedia.h"
#include "qiusislider.h"
#include "qiusivolumecontrol.h"
#include "qiusimediabutton.h"
#include "qiusistatusinfo.h"

#include <QDebug>

class QiuSiVideoMode : public QWidget
{
    Q_OBJECT
public:
    explicit QiuSiVideoMode(QWidget *parent = nullptr, const QString &path = nullptr, const QString &color = "#000000");

    QString SetVideoPath(QString path);

private:
    void MediaWidgetLayout();

    QiuSiMedia *qs_media;
    QiuSiSlider *qs_slider;
    QiuSiMediaButton *qs_mediaBtn;
    QiuSiVolumeControl *qs_volume;
    QiuSiStatusInfo *mediaInfo;

    QString mediaPath;
signals:

};

#endif // QIUSIVIDEOMODE_H
