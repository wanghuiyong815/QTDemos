#-------------------------------------------------
#
# Project created by QtCreator 2018-07-13T15:46:43
#
#-------------------------------------------------

QT       += core gui
QT       += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DemoUDPServer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    udpserverandclient.cpp


HEADERS  += mainwindow.h \
    udpserverandclient.h


FORMS    += mainwindow.ui
