#include "CarnivoreSpecimen.h"

CarnivoreSpecimen::CarnivoreSpecimen()
{
    skin_color_ = QColor(210,0,0);
}

Specimen* CarnivoreSpecimen::clone() const
{
    CarnivoreSpecimen* temp = new CarnivoreSpecimen();
    return temp;
}
