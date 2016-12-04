#-------------------------------------------------
#
# Project created by QtCreator 2016-11-28T18:40:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gzip
TEMPLATE = app


CONFIG += c++14

SOURCES += main.cpp\
        mainwindow.cpp \
    compress/zlib/easyzlib.c \
    compress/compress.cpp \
    util/util.cpp \
    decompress/decompress.cpp

HEADERS  += mainwindow.h \
    compress/zlib/easyzlib.h \
    compress/compress.h \
    util/util.h \
    decompress/decompress.h

FORMS    += mainwindow.ui
