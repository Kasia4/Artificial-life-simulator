#ifndef SIMULATIONVIEW_H
#define SIMULATIONVIEW_H

#include <QGraphicsView>

#include "SimulationScene.h"
#include "BoardEditor.h"

class SimulationView : public QGraphicsView
{
	Q_OBJECT
public:
    SimulationView(QWidget *parent = Q_NULLPTR);
    SimulationView(SimulationScene *scene, QWidget *parent = Q_NULLPTR);
    void setScene(SimulationScene *scene);
	void setBoardEditor(BoardEditor *editor);
protected:

	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);

public slots:
    void addHerbivore();
    void addCarnivore();
	void setShowColliders(bool enable);

private:
    SimulationScene* simulation_scene_;
	BoardEditor* board_editor_;

signals:
	void fieldModified(const QPoint& position);

};

#endif // SIMULATIONVIEW_H
