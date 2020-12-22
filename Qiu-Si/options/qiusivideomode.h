#ifndef QIUSIVIDEOMODE_H
#define QIUSIVIDEOMODE_H

#include <QWidget>
#include <QMessageBox>
#include <QFileInfo>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTimer>

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

    QLabel *lbl_now, *lbl_end;

    void RunSliderBtn();

    void ChangeShowTime();
private:
    void MediaWidgetLayout();


signals:

};

#endif // QIUSIVIDEOMODE_H
