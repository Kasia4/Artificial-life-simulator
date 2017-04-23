#-------------------------------------------------
#
# Project created by QtCreator 2017-04-21T17:58:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Artificial-life-simulator
TEMPLATE = app


SOURCES += main.cpp\
    SimulationEngine.cpp \
    SpecimensModel.cpp \
    BoardModel.cpp \
    BoardView.cpp \
    Specimen.cpp \
    Board.cpp \
    BoardViewObject.cpp \
    MainWindow.cpp \
    BoardField.cpp

HEADERS  += \
    SimulationEngine.h \
    SpecimensModel.h \
    BoardModel.h \
    BoardView.h \
    Specimen.h \
    Board.h \
    BoardViewObject.h \
    MainWindow.h \
    BoardField.h

FORMS    += mainwindow.ui
