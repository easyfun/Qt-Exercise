#-------------------------------------------------
#
# Project created by QtCreator 2014-12-07T20:26:56
#
#-------------------------------------------------

QT       += widgets

TARGET = ThPluginPageView
TEMPLATE = lib

DEFINES += THPLUGINPAGEVIEW_LIBRARY

SOURCES += thpluginpageview.cpp \
    pageviewcomputer.cpp

HEADERS += thpluginpageview.h\
        thpluginpageview_global.h \
    pageviewcomputer.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
