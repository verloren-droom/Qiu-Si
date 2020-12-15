#include "qiusisplashscreen.h"

QiuSiSplashScreen::QiuSiSplashScreen(QPixmap &pix)
    : QSplashScreen(pix)
    , dynamicBar(new DynamicProgressBar)
{
//    QPixmap img_2(":/images/maple_leaf.png");
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
