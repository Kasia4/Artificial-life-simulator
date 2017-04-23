#include "MainWindow.h"
#include <QApplication>

#include "SimulationEngine.h"
#include "Board.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    Board board(QPoint(5,5));
    SimulationEngine engine(board);


    return a.exec();
}
