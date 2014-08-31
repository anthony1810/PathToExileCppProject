#-------------------------------------------------
#
# Project created by QtCreator 2014-08-31T12:00:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PathOfExile
TEMPLATE = app
LIBS += -L"\usr\include\boost" -lboost_regex


SOURCES += \
    centercontrol.cpp \
    herodescription.cpp \
    heropanel.cpp \
    main.cpp \
    skillpanel.cpp \
    skillpanel2.cpp \
    Window.cpp \
    modal/Charater.cpp \
    modal/Class.cpp \
    modal/DataPopulater.cpp \
    modal/Shortest.cpp

HEADERS  += \
    centercontrol.h \
    herodescription.h \
    heropanel.h \
    skillpanel.h \
    skillpanel2.h \
    Window.h \
    modal/Charater.h \
    modal/Class.h \
    modal/DataPopulater.h \
    modal/Shortest.h \
    modal/Utility.h

SUBDIRS += \
    PathOfExile3.pro

OTHER_FILES += \
    PathOfExile.pro.user \
    modal/Skilltree.txt \
