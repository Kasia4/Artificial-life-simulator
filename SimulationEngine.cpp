#include "SimulationEngine.h"

SimulationEngine::SimulationEngine(Board& board)
   :is_started_(false)
{
    scene_.setBoard(&board);
    connect(&timer_, SIGNAL(timeout()), &scene_, SLOT(advance()));

    border = new Border(scene_.sceneRect().topLeft(), scene_.sceneRect().topRight(), scene_.sceneRect().bottomLeft(), scene_.sceneRect().bottomRight());
    QPen pen = QPen(Qt::black);

    scene_.addLine(*(border->getTopLine()),pen);
    scene_.addLine(*(border->getLeftLine()),pen);
    scene_.addLine(*(border->getRightLine()),pen);
    scene_.addLine(*(border->getBottomLine()),pen);


}



SimulationScene &SimulationEngine::getScene()
{
    return scene_;
}


void SimulationEngine::startWork()
{
    if(is_started_)return;
    is_started_ = true;
    timer_.start(1000/30);
    /*
    while(true)
    {
        if((deltaTime = timer->nsecsElapsed()) < STEP_TIME)continue;
        timer->restart();
        deltaTimeSec = (double)deltaTime/TIME_DIVISOR;
        for(Specimen* specimen : specimens_){

            specimen->move(deltaTimeSec);
        }
        if(!is_started_)break;
    }*/

}

void SimulationEngine::pause()
{
    timer_.stop();
}

void SimulationEngine::resume()
{
    timer_.start();
}

void SimulationEngine::addSpecimen(Specimen *specimen)
{
    scene_.addSpecimen(specimen);
}

void SimulationEngine::removeSpecimen(Specimen *specimen)
{
    scene_.removeSpecimen(specimen);
}



