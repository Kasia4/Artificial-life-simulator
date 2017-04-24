#ifndef HERBIVORESPECIMEN_H
#define HERBIVORESPECIMEN_H

#include "Specimen.h"

class HerbivoreSpecimen : public Specimen
{
public:
    HerbivoreSpecimen();
    SpecimenType getType() const { return SpecimenType::HERBIVORE; }
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = 0);
    Specimen* clone() const;
};

#endif // HERBIVORESPECIMEN_H
