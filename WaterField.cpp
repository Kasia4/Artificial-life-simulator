#include "WaterField.h"

WaterField::WaterField()
{
    updateAvailable();
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

void WaterField::updateAvailable()
{
    available_=true;
}

