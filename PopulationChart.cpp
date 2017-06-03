#include "PopulationChart.h"
#include "ui_PopulationChart.h"

PopulationChart::PopulationChart(QWidget *parent) :
    QWidget(parent)
    ,ui(new Ui::PopulationChart)
{
	ui->setupUi(this);
	this->setWindowTitle("Populacja");

	population_counts_.insert(SpecimenType::CARNIVORE, 0);
	population_counts_.insert(SpecimenType::HERBIVORE, 0);

	population_labels_.insert(SpecimenType::CARNIVORE, ui->carnivore_population);
	population_labels_.insert(SpecimenType::HERBIVORE, ui->herbivores_population);
}

PopulationChart::~PopulationChart()
{
	delete ui;
}

void PopulationChart::updatePopulation(SpecimenType type, int change)
{
	int new_value = population_counts_.value(type) + change;
	population_counts_.insert(type, new_value);
	population_labels_.value(type)->setText(QString::number(new_value));
}
