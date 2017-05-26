#include "SimulationView.h"


SimulationView::SimulationView(QWidget *parent)
    :QGraphicsView(parent)
{

}

SimulationView::SimulationView(QGraphicsScene *scene, QWidget *parent)
    :QGraphicsView(scene, parent)
{

}

void SimulationView::mousePressEvent(QMouseEvent *event)
{
    std::cout<<"eloszka"<<std::endl;
}

