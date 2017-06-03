#-------------------------------------------------
#
# Project created by QtCreator 2017-04-21T17:58:28
#
#-------------------------------------------------

QT       += core gui testlib
CONFIG      += console testcase

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Artificial-life-simulator
TEMPLATE = app


SOURCES += main.cpp\
    SimulationEngine.cpp \
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
    Attribute.cpp \
    State.cpp \
    SearchFoodState.cpp \
    EatState.cpp \
    SearchWaterState.cpp \
    DrinkState.cpp \
    SleepState.cpp \
    SearchPartnerState.cpp \
    ReproduceState.cpp \
    Genome.cpp \
    AttributeConditioning.cpp \
    Range.cpp \
    RunAwayState.cpp \
    BarrenField.cpp \
    SpecimenWidget.cpp \
    SimulationScene.cpp \
    Needs.cpp \
    SimulationView.cpp \
    Senses.cpp \
    SpecimenSenses.cpp \
    FocusRing.cpp \
    InitDialog.cpp \
    BoardEditor.cpp \
    PopulationChart.cpp \
    StateFactory.cpp \
    StateAttributeFactorMap.cpp \
    SimulationObject.cpp


HEADERS  += \
    SimulationEngine.h \
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
    Attribute.h \
    State.h \
    SearchFoodState.h \
    EatState.h \
    SearchWaterState.h \
    DrinkState.h \
    SleepState.h \
    SearchPartnerState.h \
    ReproduceState.h \
    Genome.h \
    AttributeConditioning.h \
    AttributeType.h \
    Range.h \
    RunAwayState.h \
    BarrenField.h \
    SpecimenWidget.h \
    SimulationScene.h \
    NeedType.h \
    Needs.h \
    SimulationView.h \
    Senses.h \
    SpecimenSenses.h \
    FocusRing.h \
    InitDialog.h \
    BoardEditor.h \
    PopulationChart.h \
    StateFactory.h \
    States.h \
    StateAttributeFactorMap.h \
    StateType.h \
    SimulationObject.h

FORMS    += \
    SpecimenWidget.ui \
    InitDialog.ui \
    BoardEditor.ui \
    MainWindow.ui \
    PopulationChart.ui

RESOURCES += \
    need_icons.qrc
