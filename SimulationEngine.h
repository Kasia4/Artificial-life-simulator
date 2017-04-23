#ifndef SIMULATIONENGINE_H
#define SIMULATIONENGINE_H

#include <QObject>
#include <QList>

#include "Board.h"
#include "Specimen.h"

class SimulationEngine: public QObject
{
    Q_OBJECT
public:
    SimulationEngine(Board& board);
    Board* getBoard() const;
    QList<Specimen>& getSpecimens();
public slots:
    void pause();
    void resume();


private:
    QList<Specimen> specimens_;
    Board* board_;



};

#endif // SIMULATIONENGINE_H
