#include "SimulationView.h"


SimulationView::SimulationView(QWidget *parent)
    :QGraphicsView(parent)
{
    setOptimizationFlags(QGraphicsView::DontSavePainterState | QGraphicsView::DontClipPainter
                         | QGraphicsView::DontAdjustForAntialiasing);
}

SimulationView::SimulationView(SimulationScene *scene, QWidget *parent)
    :QGraphicsView(scene, parent)
{
    simulation_scene_ = scene;
}

void SimulationView::setScene(SimulationScene *scene)
{
    simulation_scene_ = scene;
    QGraphicsView::setScene(scene);
}



void SimulationView::mousePressEvent(QMouseEvent *event)
{
    QGraphicsView::mousePressEvent(event);
}

void SimulationView::addHerbivore()
{
    simulation_scene_->addRandomSpecimen(SpecimenType::HERBIVORE);
}

void SimulationView::addCarnivore()
{
    simulation_scene_->addRandomSpecimen(SpecimenType::CARNIVORE);
}

void SimulationView::setShowColliders(bool enable)
{
    simulation_scene_->setShowColliders(enable);
}


