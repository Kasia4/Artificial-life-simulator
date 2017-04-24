#ifndef SPECIMENFACTORY_H
#define SPECIMENFACTORY_H

#include <QMap>
#include "HerbivoreSpecimen.h"
#include "CarnivoreSpecimen.h"

class SpecimenFactory
{
public:
    static SpecimenFactory& getInstance();
    void registerSpecimen(SpecimenType type, Specimen* prototype);
    Specimen* create(SpecimenType type);

private:
    QMap<SpecimenType, Specimen*> prototypes_;

    SpecimenFactory();
    SpecimenFactory( const SpecimenFactory & ) = delete;
    SpecimenFactory& operator=(const SpecimenFactory&) = delete;


};

#endif // SPECIMENFACTORY_H
