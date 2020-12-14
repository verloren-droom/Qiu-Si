#include "qiusisplashscreen.h"

QiuSiSplashScreen::QiuSiSplashScreen(QPixmap &img) :
    QSplashScreen(img)
{
    dynamicBar = new DynamicProgressBar;
    dynamicBar->move(width() / 2, height() / 2);
}

QiuSiSplashScreen::~QiuSiSplashScreen()
{
    delete  dynamicBar;
}

void QiuSiSplashScreen::UpdateProgressBar()
{
    static int num{0};
    dynamicBar->setValue(num);
    num++;
}
