#include "CarnivoreSpecimen.h"

CarnivoreSpecimen::CarnivoreSpecimen(Specimen* first_parent, Specimen* second_parent)
    :Specimen(first_parent, second_parent)
{
}

Specimen* CarnivoreSpecimen::clone() const
{
	CarnivoreSpecimen* temp = new CarnivoreSpecimen();
	return temp;
}

QColor CarnivoreSpecimen::skinColor() const
{
    return QColor(210, 0, 0);
}
