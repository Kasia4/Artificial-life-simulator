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
	if(output_file_.isOpen())
		output_file_.close();
}

void PopulationChart::setStoreTimer(qreal rate)
{
	store_timer_.start(rate);
	output_file_.setFileName("myfile.txt");
	std::cout<< (output_file_.open( QIODevice::ReadWrite | QIODevice::Truncate ) ? "tak" : "nie") <<std::endl;

	connect(&store_timer_, SIGNAL(timeout()), this, SLOT(storePopulation()));
}

void PopulationChart::updatePopulation(SpecimenType type, int change)
{
	int new_value = population_counts_.value(type) + change;
	population_counts_.insert(type, new_value);
	population_labels_.value(type)->setText(QString::number(new_value));
}

void PopulationChart::storePopulation()
{
	if(output_file_.isOpen())
	{
		QTextStream out(&output_file_);
		out<<population_counts_.value(SpecimenType::CARNIVORE)<<"\t"<<population_counts_.value(SpecimenType::HERBIVORE)<<"\n";
	}


}
