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
    HerbivoreSpecimen(Specimen* first_parent = nullptr, Specimen* second_parent = nullptr);
    SpecimenType getSpec() const { return SpecimenType::HERBIVORE; }
    Specimen* clone() const;
    QColor skinColor() const;

private:
    bool shouldRunAway();
};

#endif // HERBIVORESPECIMEN_H
