#ifndef SIMULATIONENGINE_H
#define SIMULATIONENGINE_H

#include <QObject>
#include <QList>
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>

#include "Board.h"
#include "Specimen.h"

class SimulationEngine: public QObject
{
    Q_OBJECT
public:
    const qint64 STEP_TIME =    1000000000;
    const qint64 TIME_DIVISOR = 1000000000;
    SimulationEngine(Board& board);
    Board* getBoard() const;
    QGraphicsScene& getScene();
    QList<Specimen*>& getSpecimens();


public slots:
    void startWork();
    void pause();
    void resume();
    void addSpecimen(Specimen* specimen);
    void removeSpecimen(Specimen* specimen);

private slots:
    void updateBoardSize(const QPoint& size);
    void replaceField(BoardField* old_field, BoardField* new_field);
private:
    QList<Specimen*> specimens_;
    QTimer timer_;
    Board* board_;
    bool is_started_;
    QGraphicsScene scene_;



};

#endif // SIMULATIONENGINE_H
