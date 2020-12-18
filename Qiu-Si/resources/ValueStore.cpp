#include "ValueStore.h"

Q_GLOBAL_STATIC(ValueStore, valueStore)

ValueStore *ValueStore::instance()
{
    return valueStore();
}

int ValueStore::fontSize{9};
QString ValueStore::fontColor{"#000000"};
bool ValueStore::fontBold{false};
bool ValueStore::fontItalic{false};
QString ValueStore::themeColor{"#ffffff"};

void ValueStore::changeFontSize(int s)
{
    fontSize = s;
}

void ValueStore::changeFontColor(QString color)
{
    fontColor = color;
}

void ValueStore::changeFontBold(bool d)
{
    fontBold = d;
}

void ValueStore::changeFontItalic(bool d)
{
    fontItalic = d;
}

void ValueStore::changeThemeColor(QString color)
{
    themeColor = color;
}

QColor ValueStore::strToColor(QString color)
{
    return QColor(color.toUInt(NULL, 16));
}
