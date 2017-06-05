#include "MainWindow.h"

#include <QApplication>
#include <QGraphicsView>
#include <QDebug>
#include <QTableView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

	SimulationEngine engine;
	MainWindow main_window;

	main_window.start(&engine);

	return a.exec();
}

