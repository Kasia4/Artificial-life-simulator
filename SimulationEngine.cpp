#include "SimulationEngine.h"

SimulationEngine::SimulationEngine(Board& board)
   :board_(&board)
{
    connect(&board, SIGNAL(fieldSizeChanged(const QPoint&)), this, SLOT(updateBoardSize(const QPoint&)));
    connect(&board, SIGNAL(fieldReplaced(BoardField*,BoardField*)), this, SLOT(replaceField(BoardField*,BoardField*)));

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

void SimulationEngine::replaceField(BoardField *old_field, BoardField *new_field)
{
    scene_.removeItem(old_field);
    scene_.addItem(new_field);
}
