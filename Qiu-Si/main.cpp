#include "qiusi.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QiuSi w;
    w.show();
    return a.exec();
}
