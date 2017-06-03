#ifndef SIMULATIONOBJECT_H
#define SIMULATIONOBJECT_H

#include <QObject>
#include <QGraphicsItem>

class SimulationObject : public QObject, public QGraphicsItem
{
	Q_OBJECT
public:
	explicit SimulationObject(QObject *parent = 0);
};

#endif // SIMULATIONOBJECT_H
