#include "SimulationView.h"


SimulationView::SimulationView(QWidget *parent)
    :QGraphicsView(parent)
	,editor_field_type_(FieldType::VOID)
{
    setOptimizationFlags(QGraphicsView::DontSavePainterState | QGraphicsView::DontClipPainter
                         | QGraphicsView::DontAdjustForAntialiasing);
}

SimulationView::SimulationView(SimulationScene *scene, QWidget *parent)
    :QGraphicsView(scene, parent)
{
    simulation_scene_ = scene;
}

void SimulationView::setScene(SimulationScene *scene)
{
    simulation_scene_ = scene;
    QGraphicsView::setScene(scene);
}



void SimulationView::mousePressEvent(QMouseEvent *event)
{
	if(event->button() == Qt::RightButton)
	{
		editor_field_type_ = FieldType::VOID;
	}
	if(editor_field_type_ != FieldType::VOID)
	{
		QPoint field_coordinates = simulation_scene_->getBoard()->getFieldPositionByPixel(event->pos());
		simulation_scene_->getBoard()->replaceField(field_coordinates, editor_field_type_);
	}
	else
	{
		QGraphicsView::mousePressEvent(event);
	}
}

void SimulationView::addHerbivore()
{
    simulation_scene_->addRandomSpecimen(SpecimenType::HERBIVORE);
}

void SimulationView::addCarnivore()
{
    simulation_scene_->addRandomSpecimen(SpecimenType::CARNIVORE);
}

void SimulationView::setShowColliders(bool enable)
{
	simulation_scene_->setShowColliders(enable);
}

void SimulationView::setEditorFieldType(FieldType type)
{
	editor_field_type_ = type;
}


