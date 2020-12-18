#ifndef GLOBALTEST_H
#define GLOBALTEST_H

extern int x;

#include <QGlobalStatic>
#include <QDebug>
#define GLOBALTEST globalTest::instance()

class globalTest
{
private:
public:
    globalTest(){}

    static globalTest* instance();

    int x;
    void test();

};

#endif // GLOBALTEST_H
