/* CarnivoreSpecimen.h
 * author: Katarzyna Rybacka
 * The CarnivoreSpecimen class provides
 * carnivore type specimen
 */

#ifndef CARNIVORESPECIMEN_H
#define CARNIVORESPECIMEN_H

#include "Specimen.h"

class CarnivoreSpecimen : public Specimen
{
public:
    CarnivoreSpecimen();
    SpecimenType getType() const { return SpecimenType::CARNIVORE; }
    Specimen* clone() const;
};

#endif // CARNIVORESPECIMEN_H
