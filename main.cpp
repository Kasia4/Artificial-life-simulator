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
        board.replaceField(QPoint(board.getWidth()-1-i,i), FieldType::WATER);
        board.replaceField(QPoint(board.getWidth()-1-i,i+1), FieldType::WATER);
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
    spec1->setSize(12);
    spec1->setRotation(qDegreesToRadians(30.0));

    spec1->setVelocity(0.1);
    engine.addSpecimen(spec1);
    spec2->setPos(20,60);
    spec2->setSize(15);
    spec2->setVelocity(0.15);
    engine.addSpecimen(spec2);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Board board(QPoint(15,15));
    board.setFieldSize(20);
    SimulationEngine engine(board);
    setCustomBoard(board);
    createSpecimans(engine);
    engine.startWork();
    MainWindow main_window;
    main_window.setBoardView(&(engine.getScene()));
    main_window.show();
    return a.exec();
}

