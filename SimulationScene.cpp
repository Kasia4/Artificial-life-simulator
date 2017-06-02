#include "SimulationScene.h"

SimulationScene::SimulationScene()
{
	needs_timer_.start(5000);
    specimen_widget_ = new SpecimenWidget();
	specimen_widget_->setHidden(true);
    specimen_widget_proxy_ = addWidget(specimen_widget_);
    specimen_widget_proxy_->setZValue(1);
    specimen_widget_proxy_->setEnabled(false);
	specimen_widget_proxy_->setOpacity(0.6);
    specimen_widget_proxy_->setAcceptHoverEvents(false);
    specimen_widget_proxy_->setFocusPolicy(Qt::NoFocus);
}

void SimulationScene::addSpecimen(Specimen *specimen)
{
    specimens_.insert(specimen);
    addItem(specimen);
    connect(specimen, SIGNAL(hoverEnter(Specimen*)), this , SLOT(showSpecimenWidget(Specimen*)));
    connect(specimen, SIGNAL(hoverLeave()), this , SLOT(hideSpecimenWidget()));
    connect(specimen, SIGNAL(killed(Specimen*)), this, SLOT(removeSpecimen(Specimen*)));
	connect(&needs_timer_, SIGNAL(timeout()), specimen, SLOT(chooseNeed()));
	specimen->setVisible(true);
	emit populationChanged(specimen->getSpec(), 1);
}

void SimulationScene::addRandomSpecimen(SpecimenType type)
{
    std::cout<<"czesc owsiak ty skurwysynu\n";
    Specimen* new_specimen = SpecimenFactory::getInstance().create(type);
    std::uniform_real_distribution<> x_gen(0, board_->getSurfaceSize().x());
    std::uniform_real_distribution<> y_gen(0, board_->getSurfaceSize().y());


    new_specimen->setPos(x_gen(Randomizer::rand_gen()), y_gen(Randomizer::rand_gen()));
    //new_specimen->setVelocity(1);
	new_specimen->setAngularVelocity(0.5);
    new_specimen->setMove(true);
    addSpecimen(new_specimen);
}

void SimulationScene::removeSpecimen(Specimen *specimen)
{
    specimens_.remove(specimen);
    removeItem(specimen);
    specimen->deleteLater();
	disconnect(specimen, SIGNAL(hoverEnter(Specimen*)), this , SLOT(showSpecimenWidget(Specimen*)));
	disconnect(specimen, SIGNAL(hoverLeave()), this , SLOT(hideSpecimenWidget()));
	emit populationChanged(specimen->getSpec(), -1);

}

Board* SimulationScene::getBoard() const
{
    return board_;
}

void SimulationScene::setShowColliders(bool enable)
{
    for(Specimen* specimen: specimens_)
    {
        specimen->getSensesCollider().setVisiblity(enable);
    }
}

void SimulationScene::setBoard(Board* board)
{
    setSceneRect(board->boundingRect());
    board_ = board;

    connect(board_, SIGNAL(fieldSizeChanged(const QPoint&)), this, SLOT(updateBoardSize(const QPoint&)));
    connect(board_, SIGNAL(fieldReplaced(BoardField*,BoardField*)), this, SLOT(replaceField(BoardField*,BoardField*)));
    updateBoardSize(board_->getSize());
}

void SimulationScene::updateBoardSize(const QPoint &size)
{
    Q_UNUSED(size);
    const MapTable& map = board_->getFields();
    for(MapColumn column : map)
    {
        for(BoardField* field : column)
        {
            addItem(field);
        }
    }
}

void SimulationScene::replaceField(BoardField *old_field, BoardField *new_field)
{
    removeItem(old_field);
    addItem(new_field);
}

void SimulationScene::showSpecimenWidget(Specimen *specimen)
{
	specimen_widget_->connectSpecimen(specimen);
}

void SimulationScene::hideSpecimenWidget()
{
	specimen_widget_->disconnectSpecimen();
}

void SimulationScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    specimen_widget_proxy_->setPos(event->scenePos());
    QGraphicsScene::mouseMoveEvent(event);
}

