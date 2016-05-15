#-------------------------------------------------
#
# Project created by QtCreator 2016-05-03T22:14:44
#
#-------------------------------------------------

QT       += core gui \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Taiko2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    game.cpp \
    result.cpp

HEADERS  += mainwindow.h \
    game.h \
    result.h

FORMS    += mainwindow.ui \
    game.ui \
    result.ui

RESOURCES += \
    picture.qrc \
    music.qrc
