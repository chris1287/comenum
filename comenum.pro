#-------------------------------------------------
#
# Project created by QtCreator 2013-06-06T11:41:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = comenum
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp

HEADERS  += dialog.h

FORMS    += dialog.ui

OTHER_FILES +=

include(./qextserialport/src/qextserialport.pri)

RESOURCES += \
    resources.qrc

RC_FILE = comenum.rc
