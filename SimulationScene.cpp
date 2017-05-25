#include "SimulationScene.h"

SimulationScene::SimulationScene()
{
    specimen_widget_ = addWidget(new SpecimenWidget());
    specimen_widget_->setZValue(1);
    specimen_widget_->setEnabled(false);
    specimen_widget_->setOpacity(0);
    specimen_widget_->setAcceptHoverEvents(false);
}

void SimulationScene::showSpecimenWidget(Specimen *specimen)
{
    specimen_widget_->setEnabled(true);
    specimen_widget_->setOpacity(0.6);
}

void SimulationScene::hideSpecimenWidget()
{
    specimen_widget_->setEnabled(true);
    specimen_widget_->setOpacity(0);
}

void SimulationScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    specimen_widget_->setPos(event->scenePos());
    QGraphicsScene::mouseMoveEvent(event);
}
