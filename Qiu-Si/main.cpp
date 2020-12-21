#include "bin/qiusi.h"

#include <QApplication>
#include <QElapsedTimer>
#include <QDesktopWidget>
#include <QTextCodec>

#include "resources/qiusisplashscreen.h"

#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QiuSiSplashScreen splash(":img/images/maple.png");
    QElapsedTimer *timer = new QElapsedTimer;

    QTextCodec::setCodecForLocale(QTextCodec::codecForName( "UTF-8" ));
//    QTextCodec::setCodecForTr(QTextCodec::codecForName( "UTF-8" ));        //支持Tr中文
//    QTextCodec::setCodecForCStrings(QTextCodec::codecForName( "UTF-8" )); //支持中文文件名显示
    timer->start();

    // 设置启动画面在屏幕正中显示
    splash.move((QApplication::desktop()->width() - splash.width()) / 2, (QApplication::desktop()->height() - splash.height()) / 2);
    splash.show();
    QiuSi w;
    a.setFont(w.QiusiFont());
    w.show();
    qDebug() << QString("Startup time: %1").arg(timer->elapsed());
    splash.finish(&w);
    return a.exec();
}
