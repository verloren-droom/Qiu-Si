QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    DialogWidget/aboutdia.cpp \
    DialogWidget/tinctselect.cpp \
    ValueStore.cpp \
    dynamicprogressbar.cpp \
    main.cpp \
    DialogWidget/optionsdia.cpp \
    qiusi.cpp \
    qiusisplashscreen.cpp

HEADERS += \
    DialogWidget/aboutdia.h \
    DialogWidget/optionsdia.h \
    DialogWidget/tinctselect.h \
    JsonKeyword.h \
    ValueStore.h \
    dynamicprogressbar.h \
    qiusi.h \
    qiusisplashscreen.h

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
