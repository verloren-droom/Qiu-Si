#ifndef VALUESTORE_H
#define VALUESTORE_H

#include <QString>
#include <QColor>

// 存储设置对话框中的值
struct ValueStore
{
    ValueStore();
    static int fontSize;
    static QString fontColor;
    static bool fontBold;
    static bool fontItalic;
    static QString themeColor;

    static void changeFontSize(int s);
    static void changeFontColor(QString color);
    static void changeFontBold(bool d);
    static void changeFontItalic(bool d);
    static void changeThemeColor(QString color);

    static QColor strToColor(QString color);
};

#endif // VALUESTORE_H
