#include "SimulationEngine.h"

SimulationEngine::SimulationEngine(Board& board)
   :board_(&board)
{
    is_started_=false;
    connect(&board, SIGNAL(fieldSizeChanged(const QPoint&)), this, SLOT(updateBoardSize(const QPoint&)));
    connect(&board, SIGNAL(fieldReplaced(BoardField*,BoardField*)), this, SLOT(replaceField(BoardField*,BoardField*)));
    connect(&timer_, SIGNAL(timeout()), &scene_, SLOT(advance()));


    updateBoardSize(board_->getSize());

}

Board* SimulationEngine::getBoard() const
{
    return board_;
}

QGraphicsScene& SimulationEngine::getScene()
{
    return scene_;
}

QList<Specimen*>& SimulationEngine::getSpecimens()
{
    return specimens_;
}

void SimulationEngine::startWork()
{
    if(is_started_)return;
    is_started_ = true;
    timer_.start(1000 / 33);
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

}

void SimulationEngine::resume()
{

}

void SimulationEngine::addSpecimen(Specimen *specimen)
{
    specimens_.append(specimen);
    scene_.addItem(specimen);
}

void SimulationEngine::removeSpecimen(Specimen *specimen)
{
    specimens_.removeOne(specimen);
    scene_.removeItem(specimen);
}

void SimulationEngine::updateBoardSize(const QPoint &size)
{
    const MapTable& map = board_->getFields();
    for(MapColumn column : map)
    {
        for(BoardField* field : column)
        {
            scene_.addItem(field);
        }
    }
}

void SimulationEngine::replaceField(BoardField *old_field, BoardField *new_field)
{
    scene_.removeItem(old_field);
    scene_.addItem(new_field);
}
