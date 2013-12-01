#-------------------------------------------------
#
# Project created by QtCreator 2013-11-13T21:21:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DoctorWHOives
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    professor.cpp \
    Markup.cpp \
    details.cpp \
    addquerido.cpp

HEADERS  += mainwindow.h \
    professor.h \
    Markup.h \
    details.h \
    addquerido.h

FORMS    += mainwindow.ui \
    details.ui \
    addquerido.ui

RESOURCES += \
    Resources.qrc

QMAKE_CXXFLAGS = -std=c++11
