#ifndef SIMULATIONSCENE_H
#define SIMULATIONSCENE_H

#include <QGraphicsScene>


#include "ItemType.h"
#include "SpecimenWidget.h"
#include "HoverSpecimenEventFilter.h"

#include <iostream>
#include <QPointer>
#include <QGraphicsProxyWidget>
#include <QGraphicsSceneMouseEvent>

class SimulationScene : public QGraphicsScene
{
    Q_OBJECT
public:
    SimulationScene();
    virtual ~SimulationScene() {};

public slots:
    void showSpecimenWidget(Specimen* specimen);
    void hideSpecimenWidget();
protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
private:
    SpecimenWidget* specimen_widget_;
    QGraphicsProxyWidget* specimen_widget_proxy_;
};

#endif // SIMULATIONSCENE_H
