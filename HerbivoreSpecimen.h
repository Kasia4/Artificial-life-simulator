/* HerbivoreSpecimen.h
 * author: Katarzyna Rybacka
 * The HerbivoreSpecimen class provides herbivore type specimen
 */
#ifndef HERBIVORESPECIMEN_H
#define HERBIVORESPECIMEN_H

#include "Specimen.h"

class HerbivoreSpecimen : public Specimen
{
public:
    HerbivoreSpecimen();
    SpecimenType getSpec() const { return SpecimenType::HERBIVORE; }
    Specimen* clone() const;
private:
    bool shouldRunAway();
};

#endif // HERBIVORESPECIMEN_H
