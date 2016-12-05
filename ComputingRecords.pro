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
    legendService.cpp \
    dataaccess.cpp \
    computer.cpp \
    computerService.cpp

HEADERS += \
    consoleui.h \
    legend.h \
    legendService.h \
    dataaccess.h \
    computer.h \
    computerService.h
