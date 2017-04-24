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
    Board board(QPoint(30,30));
    board.setFieldSize(10);
    SimulationEngine engine(board);
    QGraphicsView sceneView(&engine.getScene());

    WaterField* water = new WaterField();

    board.replaceField(QPoint(7,7), water);

    sceneView.show();

    return a.exec();
}
