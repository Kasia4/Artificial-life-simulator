#include "BarrenField.h"

BarrenField::BarrenField()
{

}

BoardField *BarrenField::clone() const
{
    BarrenField* temp = new BarrenField;
    return temp;
}

QColor BarrenField::getColor() const
{
    return QColor(Qt::lightGray);
}

