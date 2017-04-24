#-------------------------------------------------
#
# Project created by QtCreator 2017-04-21T17:58:28
#
#-------------------------------------------------

QT       += core gui
CONFIG      += console

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
    MainWindow.cpp \
    BoardField.cpp \
    GroundField.cpp \
    WaterField.cpp \
    FieldFactory.cpp \
    HerbivoreSpecimen.cpp \
    CarnivoreSpecimen.cpp \
    SpecimenFactory.cpp

HEADERS  += \
    SimulationEngine.h \
    SpecimensModel.h \
    BoardModel.h \
    BoardView.h \
    Specimen.h \
    Board.h \
    MainWindow.h \
    BoardField.h \
    GroundField.h \
    WaterField.h \
    FieldFactory.h \
    HerbivoreSpecimen.h \
    CarnivoreSpecimen.h \
    SpecimenFactory.h

FORMS    += mainwindow.ui
