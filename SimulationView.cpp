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

void SimulationView::setBoardEditor(BoardEditor* editor)
{
	board_editor_ = editor;
	connect(this, &SimulationView::fieldModified, editor, &BoardEditor::updateLastField);
}



void SimulationView::mousePressEvent(QMouseEvent *event)
{
	if(event->button() == Qt::RightButton)
	{
		editor_field_type_ = FieldType::VOID;
	}
	QGraphicsView::mousePressEvent(event);
}

void SimulationView::mouseMoveEvent(QMouseEvent* event)
{
	if(event->buttons() & Qt::LeftButton)
	{
		QPoint field_position = simulation_scene_->getBoard()->getFieldPositionByPixel(event->pos());
		if(editor_field_type_ != FieldType::VOID && board_editor_->getLastField() != field_position)
		{
			simulation_scene_->getBoard()->replaceField(field_position, editor_field_type_);
			emit fieldModified(field_position);
		}
	}
	QGraphicsView::mousePressEvent(event);
}

void SimulationView::mouseReleaseEvent(QMouseEvent* event)
{
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

void SimulationView::setEditorFieldType(FieldType type)
{
	editor_field_type_ = type;
}


