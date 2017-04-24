#include "WaterField.h"

WaterField::WaterField()
{

}

BoardField *WaterField::clone() const
{
    WaterField* temp = new WaterField;
    return temp;
}

void WaterField::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->fillRect(boundingRect(), QColor(Qt::blue));
}

