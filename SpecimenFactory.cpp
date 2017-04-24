#include "SpecimenFactory.h"

SpecimenFactory::SpecimenFactory()
{
    registerSpecimen(SpecimenType::HERBIVORE, new HerbivoreSpecimen);
    registerSpecimen(SpecimenType::CARNIVORE, new CarnivoreSpecimen);
}
SpecimenFactory &SpecimenFactory::getInstance()
{
    static SpecimenFactory instance;
    return instance;
}

void SpecimenFactory::registerSpecimen(SpecimenType type, Specimen *prototype)
{
  prototypes_.insert(type, prototype);
}

Specimen *SpecimenFactory::create(SpecimenType type)
{
    return prototypes_.value(type)->clone();
}


