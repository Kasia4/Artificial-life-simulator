#ifndef SIMULATIONSCENE_H
#define SIMULATIONSCENE_H

#include <QGraphicsScene>

#include "Board.h"
#include "ItemType.h"
#include "SpecimenWidget.h"
#include "CarnivoreSpecimen.h"
#include "HerbivoreSpecimen.h"
#include "SpecimenFactory.h"
#include "Randomizer.h"

#include <iostream>
#include <QPointer>
#include <QGraphicsProxyWidget>
#include <QGraphicsSceneMouseEvent>
#include <random>

class SimulationScene : public QGraphicsScene
{
    Q_OBJECT
public:
    SimulationScene();
    virtual ~SimulationScene() {};
    void addSpecimen(Specimen* specimen);
    void addRandomSpecimen(SpecimenType type);


    void setShowColliders(bool enable);

    Board* getBoard() const;
    void setBoard(Board *board);

public slots:
    void updateBoardSize(const QPoint& size);
    void replaceField(BoardField* old_field, BoardField* new_field);
    void removeSpecimen(Specimen* specimen);

    void showSpecimenWidget(Specimen* specimen);
    void hideSpecimenWidget();
protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
private:
    Board* board_;
    QSet<Specimen*> specimens_;

    SpecimenWidget* specimen_widget_;
    QGraphicsProxyWidget* specimen_widget_proxy_;

signals:
	void populationChanged(SpecimenType type, int change);
};

#endif // SIMULATIONSCENE_H
