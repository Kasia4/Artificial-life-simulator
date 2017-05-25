#ifndef SIMULATIONSCENE_H
#define SIMULATIONSCENE_H

#include <QGraphicsScene>


#include "ItemType.h"
#include "SpecimenWidget.h"
#include "HoverSpecimenEventFilter.h"

#include <iostream>
#include <QPointer>
#include <QGraphicsProxyWidget>

class SimulationScene : public QGraphicsScene
{
    Q_OBJECT
public:
    SimulationScene();
    virtual ~SimulationScene() {};
public slots:


private:
    QGraphicsProxyWidget* specimen_widget_;
};

#endif // SIMULATIONSCENE_H
