#-------------------------------------------------
#
# Project created by QtCreator 2014-12-02T22:03:23
#
#-------------------------------------------------

QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ThPlugin
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    thplugin.cpp \
    PageView/pageviewmath.cpp \
    ThPluginCore/ThPuginCore.cpp

HEADERS  += dialog.h \
    thplugin.h \
    PageView/pageviewmath.h
