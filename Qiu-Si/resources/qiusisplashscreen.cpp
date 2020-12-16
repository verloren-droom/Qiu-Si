#include "qiusisplashscreen.h"

QiuSiSplashScreen::QiuSiSplashScreen(const QString &imgPath, bool displayBar)
    : QSplashScreen(QPixmap(imgPath))
{
    if (displayBar)
        ShowProgressBar(imgPath);

}

void QiuSiSplashScreen::ShowProgressBar(const QString &path)
{
    dynamicBar = new DynamicProgressBar(path, this);
    dynamicBar->move((width() - dynamicBar->width()) / 2, (height()- dynamicBar->height()) / 2);
    dynamicBar->show();
}

