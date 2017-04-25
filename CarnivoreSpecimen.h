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
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = 0);
    Specimen* clone() const;
};

#endif // CARNIVORESPECIMEN_H
