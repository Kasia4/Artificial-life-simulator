#include "HerbivoreSpecimen.h"

HerbivoreSpecimen::HerbivoreSpecimen()
{
}

Specimen* HerbivoreSpecimen::clone() const
{
	HerbivoreSpecimen* temp = new HerbivoreSpecimen();
	return temp;
}

QColor HerbivoreSpecimen::skinColor() const
{
    return QColor(0,210,0);
}

bool HerbivoreSpecimen::shouldRunAway()
{
    setChaser(nearestSpecimen(SpecimenType::CARNIVORE));
    return chaser_ != nullptr;
}
