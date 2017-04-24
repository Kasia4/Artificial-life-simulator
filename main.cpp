#include "MainWindow.h"

#include <QApplication>
#include <QGraphicsView>

#include "SimulationEngine.h"
#include "Board.h"
#include "BoardModel.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Board board(QPoint(15,15));
    board.setFieldSize(20);
    SimulationEngine engine(board);
    QGraphicsView sceneView(&engine.getScene());

    std::cout<<board.getWidth()<<"no\n";
    board.replaceField(QPoint(0,0), FieldType::WATER);
    board.replaceField(QPoint(2,2), FieldType::WATER);
    board.replaceField(QPoint(3,3), FieldType::GROUND);
    //    for(int i = 0; i<3; ++i){
//        std::cout<<"elo"<<i<<"\n";
//        board.replaceField(QPoint(i,i), FieldType::WATER);
//    }
    sceneView.show();

    return a.exec();
}
