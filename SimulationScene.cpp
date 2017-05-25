#include "SimulationScene.h"

SimulationScene::SimulationScene()
{
    specimen_widget_ = addWidget(new SpecimenWidget());
    specimen_widget_->setZValue(1);
    specimen_widget_->setOpacity(0.6);
    installEventFilter(new HoverSpecimenEventFilter);
    std::cout<<"elo"<<std::endl;
}

