#ifndef QIUSISPLASHSCREEN_H
#define QIUSISPLASHSCREEN_H

#include <QSplashScreen>
#include <QPixmap>

#include "dynamicprogressbar.h"

#include <QDebug>

class QiuSiSplashScreen : public QSplashScreen
{
    Q_OBJECT
public:
    explicit QiuSiSplashScreen(const QString &imgPath = nullptr, bool displayBar = false);
    void ShowProgressBar(const QString &path);
private:
    DynamicProgressBar *dynamicBar;
//public slots:
//    void UpdateProgressBar();

signals:

};

#endif // QIUSISPLASHSCREEN_H
