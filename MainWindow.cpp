#include "MainWindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::setBoardView(QGraphicsScene *scene)
{
    QGraphicsView *boardView = findChild<QGraphicsView*>("boardView");
    boardView->setScene(scene);
    boardView->setFixedSize(602,602);
    boardView->setHorizontalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    boardView->setVerticalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );

}

MainWindow::~MainWindow()
{
    delete ui;
}
