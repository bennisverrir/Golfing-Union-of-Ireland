#-------------------------------------------------
#
# Project created by QtCreator 2016-12-12T10:13:43
#
#-------------------------------------------------

QT       += core gui
QT       += core sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TESTIDQTWIDGET
TEMPLATE = app


SOURCES += \
        main.cpp\
        mainwindow.cpp \
        service.cpp \
        dataAccess.cpp \
        computer.cpp \
        legend.cpp \
        relation.cpp \
        popupjoke.cpp

HEADERS  += \
         mainwindow.h \
         service.h \
         dataAccess.h \
         computer.h \
         legend.h \
         relation.h \
         popupjoke.h



FORMS    += \
         mainwindow.ui \
         popupjoke.ui

RESOURCES +=

DISTFILES +=
