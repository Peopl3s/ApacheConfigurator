#-------------------------------------------------
#
# Project created by QtCreator 2017-12-11T15:48:26
#
#-------------------------------------------------

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ApacheConf
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    general.cpp \
    apache.cpp \
    config.cpp \
    directorys.cpp \
    addmoduls.cpp

CONFIG += C++14
QMAKE_CXXFLAGS += -std=c++14
HEADERS  += mainwindow.h \
    apache.h \
    general.h \
    config.h \
    directorys.h \
    addmoduls.h

FORMS    += mainwindow.ui
