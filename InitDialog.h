#ifndef INITDIALOG_H
#define INITDIALOG_H

#include <QDialog>

namespace Ui {
class InitDialog;
}

class InitDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InitDialog(QWidget *parent = 0);
    ~InitDialog();

    QPoint getBoardSize() const;
    int getHerbivoreCount() const;
    int getCarnivoreCount() const;
	bool getStatsStoreBoxValue() const;
	int getTimestepValue() const;
private slots:
	void on_timestep_slider_valueChanged(int value);

private:
	Ui::InitDialog *ui;
};

#endif // INITDIALOG_H
