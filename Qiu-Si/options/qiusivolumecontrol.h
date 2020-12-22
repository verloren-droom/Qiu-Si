#ifndef QIUSIVOLUMECONTROL_H
#define QIUSIVOLUMECONTROL_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QToolButton>

#include "qiusislider.h"
#include "qiusimedia.h"
#include "qiusiplaylist.h"

class QiuSiVolumeControl : public QWidget
{
    Q_OBJECT
public:
    explicit QiuSiVolumeControl(const QString &color = "#000000", QWidget *parent = nullptr);

    void ShowPlaylist();

    QToolButton *btn_list;
    QiuSiPlaylist *playlist;
private:
    QLabel *lbl_volumeImage;

    QiuSiSlider *qs_volumeControl;

public slots:
    void ChangeImage(int s);

signals:

};

#endif // QIUSIVOLUMECONTROL_H
