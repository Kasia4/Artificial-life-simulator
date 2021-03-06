/* SpecimenFactory.h
 * author: Katarzyna Rybacka
 * The SpecimenFactory class provides Factory to create default fields by cloning prototypes
 */

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
	~SpecimenFactory();

private:
    QMap<SpecimenType, Specimen*> prototypes_;

    SpecimenFactory();
    SpecimenFactory( const SpecimenFactory & ) = delete;
    SpecimenFactory& operator=(const SpecimenFactory&) = delete;


};

#endif // SPECIMENFACTORY_H
