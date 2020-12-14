#include "qiusi.h"

#include <QApplication>
#include <QTimer>
#include <QDebug>
#include "qiusisplashscreen.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QiuSi w;
    QPixmap bgImg(":/img/images/startImg.png");
    QiuSiSplashScreen splash(bgImg);
    splash.show();
    w.show();
    splash.finish(&w);
    return a.exec();
}
