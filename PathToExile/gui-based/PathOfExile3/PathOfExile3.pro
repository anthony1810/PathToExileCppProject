#-------------------------------------------------
#
# Project created by QtCreator 2014-08-28T21:48:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PathOfExile3
TEMPLATE = app
INCLUDEPATH += /usr/include/boost
LIBS += -/usr/include/boost

SOURCES += main.cpp\
        Window.cpp \
    herodescription.cpp \
    heropanel.cpp \
    skillpanel.cpp \
    skillpanel2.cpp \
    centercontrol.cpp \
    ../../../../../../Desktop/Testing/PathOfExile3/modal/Charater.cpp \
    ../../../../../../Desktop/Testing/PathOfExile3/modal/Class.cpp \
    ../../../../../../Desktop/Testing/PathOfExile3/modal/ConnectHandler.cpp \
    ../../../../../../Desktop/Testing/PathOfExile3/modal/DataPopulater.cpp \
    ../../../../../../Desktop/Testing/PathOfExile3/modal/Shortest.cpp

HEADERS  += Window.h \
    herodescription.h \
    heropanel.h \
    skillpanel.h \
    skillpanel2.h \
    centercontrol.h \
    ../../../../../../Desktop/Testing/PathOfExile3/modal/Charater.h \
    ../../../../../../Desktop/Testing/PathOfExile3/modal/Class.h \
    ../../../../../../Desktop/Testing/PathOfExile3/modal/ConnectHandler.h \
    ../../../../../../Desktop/Testing/PathOfExile3/modal/DataPopulater.h \
    ../../../../../../Desktop/Testing/PathOfExile3/modal/Shortest.h \
    ../../../../../../Desktop/Testing/PathOfExile3/modal/Utility.h

OTHER_FILES += \
    PathOfExile3.pro.user


