#include "HerbivoreSpecimen.h"

HerbivoreSpecimen::HerbivoreSpecimen()
{
    skin_color_ = QColor(0,210,0);
}

Specimen* HerbivoreSpecimen::clone() const
{
    HerbivoreSpecimen* temp = new HerbivoreSpecimen();
    return temp;
}

bool HerbivoreSpecimen::shouldRunAway()
{
    chaser_ = nearestSpecimen(SpecimenType::CARNIVORE);
    return chaser_ != nullptr;
}
