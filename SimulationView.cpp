#include "SimulationView.h"


SimulationView::SimulationView(QWidget *parent)
	:QGraphicsView(parent)
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

void SimulationView::setBoardEditor(BoardEditor* editor)
{
	board_editor_ = editor;
	connect(this, &SimulationView::fieldModified, editor, &BoardEditor::updateLastField);
}



void SimulationView::mousePressEvent(QMouseEvent *event)
{
	if(event->button() == Qt::RightButton)
	{
		board_editor_->setFieldType(FieldType::VOID);
	}
	QGraphicsView::mousePressEvent(event);
}

void SimulationView::mouseMoveEvent(QMouseEvent* event)
{
	if(event->buttons() & Qt::LeftButton)
	{
		QPoint field_position = simulation_scene_->getBoard()->getFieldPositionByPixel(event->pos());
		FieldType field_type = board_editor_->getCurrentFieldType();
		if(field_type != FieldType::VOID && board_editor_->getLastField() != field_position)
		{
			simulation_scene_->getBoard()->replaceField(field_position, field_type);
			emit fieldModified(field_position);
		}
	}
	QGraphicsView::mousePressEvent(event);
}

void SimulationView::mouseReleaseEvent(QMouseEvent* event)
{
	Q_UNUSED(event);
	emit fieldModified(QPoint(-1,-1));
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


