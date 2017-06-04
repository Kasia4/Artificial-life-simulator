#ifndef POPULATIONCHART_H
#define POPULATIONCHART_H

#include <QWidget>
#include <QLabel>
#include <QTimer>
#include <QFile>
#include <QTextStream>
#include <iostream>


#include "Specimen.h"

namespace Ui {
class PopulationChart;
}

class PopulationChart : public QWidget
{
	Q_OBJECT

public:
	explicit PopulationChart(QWidget *parent = 0);
	~PopulationChart();

	void setStoreTimer(qreal rate);

public slots:
	void updatePopulation(SpecimenType type, int change);

private:
	Ui::PopulationChart *ui;
	QTimer store_timer_;
	QFile output_file_;

	QMap<SpecimenType, unsigned> population_counts_;
	QMap<SpecimenType, QLabel*> population_labels_;

private slots:
	void storePopulation();


};

#endif // POPULATIONCHART_H
