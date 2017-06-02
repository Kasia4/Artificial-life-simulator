#include "HerbivoreSpecimen.h"

HerbivoreSpecimen::HerbivoreSpecimen(Specimen* first_parent, Specimen* second_parent) : Specimen(first_parent, second_parent)
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
