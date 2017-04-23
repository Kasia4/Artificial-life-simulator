#include "SimulationEngine.h"

SimulationEngine::SimulationEngine(Board& board)
   :board_(&board)
{

}

Board* SimulationEngine::getBoard() const
{
    return board_;
}

QList<Specimen>& SimulationEngine::getSpecimens()
{
    return specimens_;
}

void SimulationEngine::pause()
{

}

void SimulationEngine::resume()
{

}
