#ifndef QIUSISPLASHSCREEN_H
#define QIUSISPLASHSCREEN_H

#include <QSplashScreen>

#include "dynamicprogressbar.h"

class QiuSiSplashScreen : public QSplashScreen
{
    Q_OBJECT
public:
    explicit QiuSiSplashScreen(QPixmap &img);
    ~QiuSiSplashScreen();
private:
    DynamicProgressBar *dynamicBar;
public slots:
    void UpdateProgressBar();

signals:

};

#endif // QIUSISPLASHSCREEN_H
