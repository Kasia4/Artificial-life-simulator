/* MainWindow.h
 * author: Karol Checinski
 * The MainWindow class responsibles for main application GUI
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include "SimulationEngine.h"

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

protected:
private slots:

    void on_collidersCheckBox_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;
    SimulationEngine *engine_;
};

#endif // MAINWINDOW_H
