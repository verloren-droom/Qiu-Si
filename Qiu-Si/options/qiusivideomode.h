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
#include "qiusimediabutton.h"

#include <QDebug>

class QiuSiVideoMode : public QWidget
{
    Q_OBJECT
public:
    explicit QiuSiVideoMode(QWidget *parent = nullptr, const QString &color = "#000000");
    QiuSiSlider *qs_slider;
    QiuSiMediaButton *qs_mediaBtn;

    void RunSliderBtn();

private:
    void MediaWidgetLayout();

signals:

};

#endif // QIUSIVIDEOMODE_H
