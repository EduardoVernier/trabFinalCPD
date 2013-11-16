#-------------------------------------------------
#
# Project created by QtCreator 2013-11-13T21:21:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = indexador
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    professor.cpp \
    Markup.cpp \
    details.cpp

HEADERS  += mainwindow.h \
    professor.h \
    Markup.h \
    details.h

FORMS    += mainwindow.ui \
    details.ui

RESOURCES += \
    Resources.qrc

QMAKE_CXXFLAGS = -std=c++11
