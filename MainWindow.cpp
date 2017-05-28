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

void MainWindow::setBoardView(SimulationScene *scene)
{
    ui->boardView->setScene(scene);
    ui->boardView->setFixedSize(602,602);
    ui->boardView->setHorizontalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    ui->boardView->setVerticalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::start()
{
    show();

    init_dialog_ = new InitDialog;
    connect(init_dialog_, SIGNAL(accepted()), this, SLOT(initiateSimulation()));
    init_dialog_->show();
}

void MainWindow::initiateSimulation()
{
    QPoint board_size = init_dialog_->getBoardSize();
    int carnivores = init_dialog_->getCarnivoreCount();
    int herbivores = init_dialog_->getHerbivoreCount();
    QSize view_size = ui->boardView->size();
    QPointF surface_size(view_size.width(), view_size.height());
    setSimulationEngine(new SimulationEngine(new Board(board_size, surface_size)));
    engine_->startWork();
}

void MainWindow::on_collidersCheckBox_stateChanged(int arg1)
{
    ui->boardView->setShowColliders(arg1);
}

void MainWindow::on_pauseButton_clicked()
{
    engine_->pause();
}


void MainWindow::on_resumeButton_clicked()
{
    engine_->resume();
}

void MainWindow::on_addHerbivoreButton_clicked()
{
    ui->boardView->addHerbivore();
}

void MainWindow::on_addCarnivoreButton_clicked()
{
    ui->boardView->addCarnivore();
}
