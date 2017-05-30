/* MainWindow.h
 * author: Karol Checinski
 * The MainWindow class responsibles for main application GUI
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include "SimulationEngine.h"
#include "InitDialog.h"
#include "PopulationChart.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void setSimulationEngine(SimulationEngine *engine);
    void setBoardView(SimulationScene *scene);
    ~MainWindow();

    void start();

protected:
private slots:
    void initiateSimulation();

    void on_collidersCheckBox_stateChanged(int arg1);

    void on_pauseButton_clicked();

    void on_resumeButton_clicked();

    void on_addHerbivoreButton_clicked();

    void on_addCarnivoreButton_clicked();

	void on_boardEditor_fieldTypeChanged(const FieldType &type);

	void on_stats_button_clicked();

private:
    Ui::MainWindow *ui;
    SimulationEngine *engine_;
	PopulationChart* population_chart_;
    InitDialog *init_dialog_;
};

#endif // MAINWINDOW_H
