#ifndef SIMULATIONVIEW_H
#define SIMULATIONVIEW_H

#include <QGraphicsView>
#include <iostream>

#include "SimulationScene.h"

class SimulationView : public QGraphicsView
{
public:
    SimulationView(QWidget *parent = Q_NULLPTR);
    SimulationView(SimulationScene *scene, QWidget *parent = Q_NULLPTR);
    void setScene(SimulationScene *scene);
protected:
    void mousePressEvent(QMouseEvent *event);


public slots:
    void addSpecimen();
    void setShowColliders(bool enable);


private:
    SimulationScene* simulation_scene_;
};

#endif // SIMULATIONVIEW_H
