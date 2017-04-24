#ifndef SIMULATIONENGINE_H
#define SIMULATIONENGINE_H

#include <QObject>
#include <QList>
#include <QGraphicsScene>
#include <iostream>
#include "Board.h"
#include "Specimen.h"

class SimulationEngine: public QObject
{
    Q_OBJECT
public:
    SimulationEngine(Board& board);
    Board* getBoard() const;
    QGraphicsScene& getScene();
    QList<Specimen*>& getSpecimens();
public slots:
    void pause();
    void resume();
    void addSpecimen(Specimen* specimen);
    void removeSpecimen(Specimen* specimen);

private slots:
    void updateBoardSize(const QPoint& size);
    void replaceField(BoardField* old_field, BoardField* new_field);
private:
    QList<Specimen*> specimens_;
    Board* board_;

    QGraphicsScene scene_;



};

#endif // SIMULATIONENGINE_H
