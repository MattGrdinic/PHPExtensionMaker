#-------------------------------------------------
#
# Project created by QtCreator 2012-04-03T22:15:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PHPExtensionMaker
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    extension.cpp \
    highlighter.cpp \
    processcompile.cpp

HEADERS  += mainwindow.h \
    extension.h \
    highlighter.h \
    filedata.h \
    processcompile.h

FORMS    += mainwindow.ui
