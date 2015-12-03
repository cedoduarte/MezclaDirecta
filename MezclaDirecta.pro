#-------------------------------------------------
#
# Project created by QtCreator 2015-12-03T14:31:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MezclaDirecta
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    CodigoDialog.cpp \
    ImagenDialog.cpp

HEADERS  += MainWindow.h \
    CodigoDialog.h \
    ImagenDialog.h

FORMS    += MainWindow.ui \
    CodigoDialog.ui \
    ImagenDialog.ui

QMAKE_CXXFLAGS += -std=gnu++14

RESOURCES += \
    res.qrc
