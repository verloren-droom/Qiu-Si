#include "globaltest.h"

Q_GLOBAL_STATIC(globalTest, test1);

globalTest* globalTest::instance()
{
    return test1();
}

void globalTest::test()
{
    qDebug() << x;
}
