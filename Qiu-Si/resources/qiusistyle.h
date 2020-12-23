#ifndef QIUSISTYLE_H
#define QIUSISTYLE_H

#include <QWidget>
#include <QIcon>
#include <QFont>
#include <QFontDatabase>
#include <QColor>

#include <QGlobalStatic>

class QiuSiStyle : public QWidget
{
    Q_OBJECT
public:
    explicit QiuSiStyle(QWidget *parent = nullptr);

    static QiuSiStyle *qs_style();

    QIcon QiusiIcon();

    QFont QiusiFont();

    QString QiusiButton();

    QString QiusiColorStr();

    QColor QiusiColorRgb();

signals:

};

#endif // QIUSISTYLE_H
