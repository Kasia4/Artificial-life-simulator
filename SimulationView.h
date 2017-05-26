#ifndef SIMULATIONVIEW_H
#define SIMULATIONVIEW_H

#include <QGraphicsView>
#include <iostream>

class SimulationView : public QGraphicsView
{
public:
    SimulationView(QWidget *parent = Q_NULLPTR);
    SimulationView(QGraphicsScene *scene, QWidget *parent = Q_NULLPTR);
protected:
    void mousePressEvent(QMouseEvent *event);
};

#endif // SIMULATIONVIEW_H
