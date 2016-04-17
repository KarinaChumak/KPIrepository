#-------------------------------------------------
#
# Project created by QtCreator 2016-04-12T23:13:08
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SQLite_DB
TEMPLATE = app


SOURCES += main.cpp\
        loginwindow.cpp \
    secondwindow.cpp

HEADERS  += loginwindow.h \
    secondwindow.h

FORMS    += loginwindow.ui \
    secondwindow.ui
