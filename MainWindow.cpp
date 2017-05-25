#include "MainWindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::setSimulationEngine(SimulationEngine *engine)
{
    engine_ = engine;
    setBoardView(&(engine_->getScene()));
}

void MainWindow::setBoardView(QGraphicsScene *scene)
{

    ui->boardView->setScene(scene);
    ui->boardView->setFixedSize(602,602);
    ui->boardView->setHorizontalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    ui->boardView->setVerticalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    ui->boardView->installEventFilter(new HoverSpecimenEventFilter);

}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::event(QEvent *event)
{
    if(event->type() == QEvent::GraphicsSceneHoverEnter)
    {
        std::cout<<"Jak pojebany"<<std::endl;
    }
    return QMainWindow::event(event);
}

void MainWindow::on_collidersCheckBox_stateChanged(int arg1)
{
    if(arg1 == Qt::Unchecked)engine_->hideColliders();
    if(arg1 == Qt::Checked)engine_->showColliders();
}

