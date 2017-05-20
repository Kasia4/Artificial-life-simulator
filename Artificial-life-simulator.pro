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
    BehaviourManager.cpp \
    Attribute.cpp \
    State.cpp \
    SearchFoodState.cpp \
    ChaseFoodState.cpp \
    EatState.cpp \
    SearchWaterState.cpp \
    DrinkState.cpp \
    DieState.cpp \
    SleepState.cpp \
    SearchPartnerState.cpp \
    ReproduceState.cpp
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
    BehaviourManager.h \
    Attribute.h \
    State.h \
    SearchFoodState.h \
    ChaseFoodState.h \
    EatState.h \
    SearchWaterState.h \
    DrinkState.h \
    DieState.h \
    SleepState.h \
    SearchPartnerState.h \
    ReproduceState.h \
    states.h
    Genome.h \
    AttributeConditioning.h \
    AttributeType.h

FORMS    += mainwindow.ui
