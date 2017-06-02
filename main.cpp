#include "MainWindow.h"
#include <QApplication>
#include <QGraphicsView>
#include <QDebug>
#include <QTableView>

#include "SimulationEngine.h"
#include "Board.h"
#include "BoardModel.h"
#include "HerbivoreSpecimen.h"
#include "CarnivoreSpecimen.h"
#include "CircleCollider.h"
#include "Genome.h"
#include "SpecimensModel.h"
#include "Range.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow main_window;

	main_window.start();

	return a.exec();
}

