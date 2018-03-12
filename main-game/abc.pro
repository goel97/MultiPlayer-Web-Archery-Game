#-------------------------------------------------
#
# Project created by QtCreator 2018-02-23T16:28:06
#
#-------------------------------------------------

QT       += core gui
QT       += websockets


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = abc
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    arrow.cpp \
    myplayer1.cpp \
    target.cpp \
    score.cpp \
    scoreboard.cpp \
    bow.cpp \
    gamestate.cpp \
    server.cpp \
    client.cpp \
    screenupdate.cpp

HEADERS += \
    target.h \
    arrow.h \
    myplayer1.h \
    score.h \
    scoreboard.h \
    bow.h \
    gamestate.h \
    server.h \
    client.h \
    screenupdate.h

RESOURCES += \
    resources.qrc

FORMS    +=
