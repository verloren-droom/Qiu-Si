#ifndef JSONKEYWORD_H
#define JSONKEYWORD_H

#include <QVector>
#include <QString>

struct JsonKeyword
{
    const QVector<QString> FontSet{"font", "size", "color"};
    const QVector<QString> ThemeSet{"theme", "color"};
};


#endif // JSONKEYWORD_H
