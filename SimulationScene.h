#ifndef SIMULATIONSCENE_H
#define SIMULATIONSCENE_H

#include <QGraphicsScene>


#include "ItemType.h"
#include "SpecimenWidget.h"
#include "CarnivoreSpecimen.h"
#include "HerbivoreSpecimen.h"
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
    void addSpecimen(Specimen* specimen);
    void removeSpecimen(Specimen* specimen);

    void setShowColliders(bool enable);

public slots:
    void showSpecimenWidget(Specimen* specimen);
    void hideSpecimenWidget();
protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
private:
    QSet<Specimen*> specimens_;

    SpecimenWidget* specimen_widget_;
    QGraphicsProxyWidget* specimen_widget_proxy_;
};

#endif // SIMULATIONSCENE_H
