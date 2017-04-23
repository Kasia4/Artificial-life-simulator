#ifndef BOARDMODEL_H
#define BOARDMODEL_H

#include <QObject>
#include <QAbstractTableModel>

#include "SimulationEngine.h"
#include "Board.h"

class BoardModel : public QAbstractTableModel
{
public:
    BoardModel(const SimulationEngine& engine);
    void linkEngine(const SimulationEngine& engine);
private:
    Board* board_handle_;
};

#endif // BOARDMODEL_H
