#include "MainWindow.h"
#include <QApplication>
#include <QGraphicsView>
#include <QDebug>
#include "SimulationEngine.h"
#include "Board.h"
#include "BoardModel.h"
#include "HerbivoreSpecimen.h"
#include "CarnivoreSpecimen.h"

void setCustomBoard(Board& board)
{
    for(int i = 0; i<board.getWidth()-1; ++i)
    {
        board.replaceField(QPoint(i,i), FieldType::WATER);
        board.replaceField(QPoint(i,i+1), FieldType::WATER);
    }
}

void createSpecimans(SimulationEngine& engine){
    HerbivoreSpecimen* spec = new HerbivoreSpecimen;
    spec->setPos(20,20);
    spec->setSize(20);
    spec->setVelocity(QVector2D(1,1));
    engine.addSpecimen(spec);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Board board(QPoint(15,15));
    board.setFieldSize(20);
    SimulationEngine engine(board);
    QGraphicsView sceneView(&engine.getScene());
    sceneView.setFixedSize(602,602);
    sceneView.setHorizontalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    sceneView.setVerticalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    setCustomBoard(board);
    createSpecimans(engine);
    sceneView.setSceneRect(0,0,board.getWidth()*board.getFieldSize()*2, board.getHeight()*board.getFieldSize()*2);
    engine.startWork();
    sceneView.show();
    return a.exec();
}

