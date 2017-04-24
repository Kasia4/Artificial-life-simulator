#include "SimulationEngine.h"

SimulationEngine::SimulationEngine(Board& board)
   :board_(&board)
{
    connect(&board, SIGNAL(fieldSizeChanged(const QPoint&)), this, SLOT(updateBoardSize(const QPoint&)));

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

void SimulationEngine::pause()
{

}

void SimulationEngine::resume()
{

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
