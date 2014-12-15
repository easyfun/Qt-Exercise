#-------------------------------------------------
#
# Project created by QtCreator 2014-11-27T16:59:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = thCloudDisk
TEMPLATE = app


SOURCES += main.cpp\
        thclouddisk.cpp\
    thBasic/thframe.cpp \
    thBasic/testwidget.cpp \
    thBasic/thtitlebar.cpp

HEADERS  += thclouddisk.h\
    thBasic/thframe.h \
    thBasic/testwidget.h \
    thBasic/thtitlebar.h

RESOURCES += \
    thclouddisk.qrc
