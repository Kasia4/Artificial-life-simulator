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
    SimulationEngine(Board* board);
    virtual ~SimulationEngine() {};

	SimulationScene* getScene();

public slots:
    void startWork();
    void pause();
    void resume();
    void addSpecimen(Specimen* specimen);
    void removeSpecimen(Specimen* specimen);

private:
    QTimer timer_;
    Board* board_;
    bool is_started_;
    SimulationScene scene_;
    Border* border;

};

#endif // SIMULATIONENGINE_H
