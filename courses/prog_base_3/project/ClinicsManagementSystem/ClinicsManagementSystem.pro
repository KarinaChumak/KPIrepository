#-------------------------------------------------
#
# Project created by QtCreator 2016-05-06T22:58:27
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ClinicsManagementSystem
TEMPLATE = app


SOURCES += main.cpp \
    loginwindow.cpp \
    adminwindow.cpp \
    admindoctors.cpp \
    adminpatients.cpp \
    adminpayment.cpp \
    adminnewdoctor.cpp

HEADERS  += \
    loginwindow.h \
    adminwindow.h \
    admindoctors.h \
    adminpatients.h \
    adminpayment.h \
    adminnewdoctor.h

FORMS    += \
    loginwindow.ui \
    adminwindow.ui \
    admindoctors.ui \
    adminpatients.ui \
    adminpayment.ui \
    adminnewdoctor.ui
