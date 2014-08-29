#-------------------------------------------------
#
# Project created by QtCreator 2014-08-16T18:20:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Testing
TEMPLATE = app


SOURCES += main.cpp\
    Window.cpp \
    heropanel.cpp \
    skillpanel.cpp \
    herodescription.cpp \
    skillpanel2.cpp \
    modal/Charater.cpp \
    modal/DataPopulater.cpp \
    modal/Class.cpp

HEADERS  += \
    Window.h \
    heropanel.h \
    skillpanel.h \
    herodescription.h \
    skillpanel2.h \
    modal/Charater.h \
    modal/DataPopulater.h \
    modal/Class.h \
    modal/Shortest.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    Marauder_Portrait.png
