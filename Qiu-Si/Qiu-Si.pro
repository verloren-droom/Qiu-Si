QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    help/aboutdia.cpp \
    options/tinctselect.cpp \
    options/optionsdia.cpp \
    resources/ValueStore.cpp \
    resources/dynamicprogressbar.cpp \
    resources/qiusisplashscreen.cpp \
    bin/qiusi.cpp \
    main.cpp

HEADERS += \
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
