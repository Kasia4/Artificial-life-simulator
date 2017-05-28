#include "SimulationScene.h"

SimulationScene::SimulationScene()
{
    specimen_widget_ = new SpecimenWidget();
    specimen_widget_proxy_ = addWidget(specimen_widget_);
    specimen_widget_proxy_->setZValue(1);
    specimen_widget_proxy_->setEnabled(false);
    specimen_widget_proxy_->setOpacity(0);
    specimen_widget_proxy_->setAcceptHoverEvents(false);
    specimen_widget_proxy_->setFocusPolicy(Qt::NoFocus);
}

void SimulationScene::addSpecimen(Specimen *specimen)
{
    specimens_.insert(specimen);
    addItem(specimen);
    connect(specimen, SIGNAL(hoverEnter(Specimen*)), this , SLOT(showSpecimenWidget(Specimen*)));
    connect(specimen, SIGNAL(hoverLeave()), this , SLOT(hideSpecimenWidget()));
}

void SimulationScene::addRandomSpecimen(SpecimenType type)
{
    //Specimen* new_specimen = SpecimenFactory::getInstance().create(type);
    //std::uniform_real_distribution(0, )
    //new_specimen->setPos();
    //addSpecimen(new_specimen);
}

void SimulationScene::removeSpecimen(Specimen *specimen)
{
    specimens_.remove(specimen);
    removeItem(specimen);
    disconnect(specimen, SIGNAL(hoverEnter(Specimen*)), this , SLOT(showSpecimenWidget(Specimen*)));
    disconnect(specimen, SIGNAL(hoverLeave()), this , SLOT(hideSpecimenWidget()));
}

void SimulationScene::setShowColliders(bool enable)
{
    for(Specimen* specimen: specimens_)
    {
        specimen->getSensesCollider().setVisiblity(enable);
    }
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

