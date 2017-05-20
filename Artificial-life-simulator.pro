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
    Specimen.cpp \
    Board.cpp \
    MainWindow.cpp \
    BoardField.cpp \
    GroundField.cpp \
    WaterField.cpp \
    FieldFactory.cpp \
    HerbivoreSpecimen.cpp \
    CarnivoreSpecimen.cpp \
    SpecimenFactory.cpp \
    Collider.cpp \
    Border.cpp \
    ConeCollider.cpp \
    CircleCollider.cpp \
    Gene.cpp \
    Randomizer.cpp \
    Genome.cpp \
    AttributeConditioning.cpp

HEADERS  += \
    SimulationEngine.h \
    SpecimensModel.h \
    BoardModel.h \
    Specimen.h \
    Board.h \
    MainWindow.h \
    BoardField.h \
    GroundField.h \
    WaterField.h \
    FieldFactory.h \
    HerbivoreSpecimen.h \
    CarnivoreSpecimen.h \
    SpecimenFactory.h \
    ItemType.h \
    Collider.h \
    Border.h \
    ConeCollider.h \
    CircleCollider.h \
    Gene.h \
    Randomizer.h \
    Genome.h \
    AttributeConditioning.h

FORMS    += mainwindow.ui
