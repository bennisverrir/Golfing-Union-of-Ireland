QT += core
QT -= gui
QT += core sql

CONFIG += c++11

TARGET = ComputingRecords
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    consoleui.cpp \
    legend.cpp \
    dataaccess.cpp \
    computer.cpp \
    service.cpp

HEADERS += \
    consoleui.h \
    legend.h \
    dataaccess.h \
    computer.h \
    service.h
