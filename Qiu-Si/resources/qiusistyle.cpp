#include "qiusistyle.h"

QiuSiStyle::QiuSiStyle(QWidget *parent) : QWidget(parent)
{

}

Q_GLOBAL_STATIC(QiuSiStyle, qiuSiStyle)

inline QiuSiStyle *QiuSiStyle::qs_style()
{
    return qiuSiStyle();
}

inline QIcon QiuSiStyle::QiusiIcon()
{
    return QIcon(":/icon/images/icon/maple.png");
}

inline QString QiuSiStyle::QiusiColorStr()
{
    return "#c02c38";
}

inline QColor QiuSiStyle::QiusiColorRgb()
{
    return QColor(192, 44, 56);
}

inline QFont QiuSiStyle::QiusiFont()
{
    QFont font;
    int fontIndex = QFontDatabase::addApplicationFont(":font/resources/font/hurry.ttf");
    if (fontIndex != -1)
    {
        QStringList list(QFontDatabase::applicationFontFamilies(fontIndex));
        if (list.count() > 0)
        {
            QFont font(list[0]);
            font.setPointSize(12);
            font.setBold(true);
            return font;
        }
    }
    return font;
}

inline QString QiuSiStyle::QiusiButton()
{
    return "QPushButton{"
           "background-color: white; border: 0px; border-style: outset;"
           "}"
           "QPushButton:hover{"
           "background-color: white;"
           "}"
           "QPushButton:pressed{"
           "border-style: inset;}";
}

