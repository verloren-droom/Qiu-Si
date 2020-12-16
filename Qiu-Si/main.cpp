#include "bin/qiusi.h"

#include <QApplication>
#include <QElapsedTimer>
#include <QDesktopWidget>

#include "resources/qiusisplashscreen.h"

#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QiuSiSplashScreen splash(":img/images/maple.png");
    QElapsedTimer *timer = new QElapsedTimer;
    timer->start();

    // 设置启动画面在屏幕正中显示
    splash.move((QApplication::desktop()->width() - splash.width()) / 2, (QApplication::desktop()->height() - splash.height()) / 2);
    splash.show();
    QiuSi w;
    w.show();
    qDebug() << QString("Startup time: %1").arg(timer->elapsed());
    splash.finish(&w);
    return a.exec();
}
