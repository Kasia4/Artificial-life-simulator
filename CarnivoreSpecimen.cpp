#include "CarnivoreSpecimen.h"

CarnivoreSpecimen::CarnivoreSpecimen()
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
