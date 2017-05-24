/* SimulatorEngine.h
 * author: Karol Chęciński
 * The SimulatorEngine class is main class managing simulation
 */


#ifndef SIMULATIONENGINE_H
#define SIMULATIONENGINE_H

#include <QObject>
#include <QList>
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>

#include "SimulationScene.h"
#include "Board.h"
#include "Specimen.h"
#include "Border.h"

class SimulationEngine: public QObject
{
    Q_OBJECT
public:
    SimulationEngine(Board& board);
    virtual ~SimulationEngine() {};
    Board* getBoard() const;
    SimulationScene& getScene();
    const QList<Specimen*>& getSpecimens() const;


public slots:
    void startWork();
    void pause();
    void resume();
    void addSpecimen(Specimen* specimen);
    void removeSpecimen(Specimen* specimen);
    void showColliders();
    void hideColliders();
private slots:
    void updateBoardSize(const QPoint& size);
    void replaceField(BoardField* old_field, BoardField* new_field);

private:
    QList<Specimen*> specimens_;
    QTimer timer_;
    Board* board_;
    bool is_started_;
    SimulationScene scene_;
    Border* border;


};

#endif // SIMULATIONENGINE_H
