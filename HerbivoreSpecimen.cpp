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
    chaser_ = nearestSpecimen(SpecimenType::CARNIVORE);
    return chaser_ != nullptr;
}
