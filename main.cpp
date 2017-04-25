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
    for(int i = 0; i<board.getWidth(); ++i){
        for(int j = 0; j<board.getHeight(); ++j){
            BoardField* field = &board.getField(QPoint(i,j));
            if(field->getType()==FieldType::GROUND)
            {
                dynamic_cast<GroundField*>(field)->setOvergrow(i*5);
            }
        }
    }
}

void createSpecimans(SimulationEngine& engine){
    HerbivoreSpecimen* spec1 = new HerbivoreSpecimen;
    CarnivoreSpecimen* spec2 = new CarnivoreSpecimen;
    spec1->setPos(20,20);
    spec1->setSize(20);
    spec1->setRotation(qDegreesToRadians(30.0));

    spec1->setVelocity(0.6);
    engine.addSpecimen(spec1);
    spec2->setPos(220,60);
    spec2->setSize(25);
    spec2->setRotation(qDegreesToRadians(90.0));
    spec2->setAngularVelocity(qDegreesToRadians(3.0));
    spec2->setVelocity(0.7);
    engine.addSpecimen(spec2);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Board board(QPoint(30,30));
    board.setFieldSize(10);
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

