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
    for(int i = 0; i<board.getWidth()-1; ++i){
        board.replaceField(QPoint(i,i), FieldType::WATER);
        board.replaceField(QPoint(i,i+1), FieldType::WATER);
    }
    sceneView.show();

    return a.exec();
}
