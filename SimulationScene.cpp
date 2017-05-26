#include "SimulationScene.h"

SimulationScene::SimulationScene()
{
    specimen_widget_ = new SpecimenWidget();
    specimen_widget_proxy_ = addWidget(specimen_widget_);
    specimen_widget_proxy_->setZValue(1);
    specimen_widget_proxy_->setEnabled(false);
    specimen_widget_proxy_->setOpacity(0);
    specimen_widget_proxy_->setAcceptHoverEvents(false);
}

void SimulationScene::showSpecimenWidget(Specimen *specimen)
{
    specimen_widget_->connectSpecimen(specimen);
    specimen_widget_proxy_->setEnabled(true);
    specimen_widget_proxy_->setOpacity(0.6);
}

void SimulationScene::hideSpecimenWidget()
{
    specimen_widget_->disconnectSpecimen();
    specimen_widget_proxy_->setEnabled(false);
    specimen_widget_proxy_->setOpacity(0);
}

void SimulationScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    specimen_widget_proxy_->setPos(event->scenePos());
    QGraphicsScene::mouseMoveEvent(event);
}
