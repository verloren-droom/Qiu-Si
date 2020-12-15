#include "bin/qiusi.h"

#include <QApplication>
#include <QElapsedTimer>
#include <QTimer>

#include "resources/qiusisplashscreen.h"

#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPixmap img_1(":/images/maple.png");
    QiuSiSplashScreen splash(img_1);
    splash.show();
    QiuSi w;
    w.show();
    splash.finish(&w);
    return a.exec();
}
