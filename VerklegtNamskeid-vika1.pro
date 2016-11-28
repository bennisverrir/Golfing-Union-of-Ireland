QT += core
QT -= gui

CONFIG += c++11

TARGET = VerklegtNamskeid-vika1
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    presentation.cpp \
    domain.cpp \
    data.cpp

HEADERS += \
    presentation.h \
    domain.h \
    data.h
