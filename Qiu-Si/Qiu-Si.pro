QT       += core gui
QT       += multimedia
QT       += multimediawidgets
QT       += sql
QT       += winextras
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    options/qiusimedia.cpp \
    options/qiusimediabutton.cpp \
    options/qiusiplaylist.cpp \
    options/qiusislider.cpp \
    options/qiusispinbox.cpp \
    options/qiusistatusinfo.cpp \
    options/qiusivideomode.cpp \
    options/qiusivolumecontrol.cpp \
    resources/qiusistyle.cpp \
    test/globaltest.cpp \
    help/aboutdia.cpp \
    options/tinctselect.cpp \
    options/optionsdia.cpp \
    resources/ValueStore.cpp \
    resources/dynamicprogressbar.cpp \
    resources/qiusisplashscreen.cpp \
    bin/qiusi.cpp \
    main.cpp

HEADERS += \
    options/qiusimedia.h \
    options/qiusimediabutton.h \
    options/qiusiplaylist.h \
    options/qiusislider.h \
    options/qiusispinbox.h \
    options/qiusistatusinfo.h \
    options/qiusivideomode.h \
    options/qiusivolumecontrol.h \
    resources/qiusistyle.h \
    test/globaltest.h \
    help/aboutdia.h \
    options/optionsdia.h \
    options/tinctselect.h \
    resources/JsonKeyword.h \
    resources/ValueStore.h \
    resources/dynamicprogressbar.h \
    resources/qiusisplashscreen.h \
    bin/qiusi.h

FORMS += \
    qiusi.ui

TRANSLATIONS += \
    Qiu-Si_zh_CN.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Res.qrc
