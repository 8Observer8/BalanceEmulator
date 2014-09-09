#-------------------------------------------------
#
# Project created by QtCreator 2014-09-09T11:18:22
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BalanceEmulator
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    Sender.cpp \
    SettingsDialog.cpp

HEADERS  += MainWindow.h \
    Sender.h \
    SettingsDialog.h \
    PortError.h

FORMS    += MainWindow.ui \
    SettingsDialog.ui
