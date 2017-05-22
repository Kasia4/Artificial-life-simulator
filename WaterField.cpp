#include "WaterField.h"

WaterField::WaterField()
{

}

BoardField *WaterField::clone() const
{
    WaterField* temp = new WaterField;
    return temp;
}

QColor WaterField::getColor() const
{
    return QColor(Qt::blue);
}

