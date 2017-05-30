#ifndef POPULATIONCHART_H
#define POPULATIONCHART_H

#include <QWidget>
#include <QLabel>

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

public slots:
	void updatePopulation(SpecimenType type, int change);

private:
	Ui::PopulationChart *ui;

	QMap<SpecimenType, unsigned> population_counts_;
	QMap<SpecimenType, QLabel*> population_labels_;


};

#endif // POPULATIONCHART_H
