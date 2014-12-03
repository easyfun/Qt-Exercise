#-------------------------------------------------
#
# Project created by QtCreator 2014-12-02T22:03:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ThPlugin
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    thplugin.cpp

HEADERS  += dialog.h \
    ThPluginCore/ThPuginCore.h \
    thplugin.h
