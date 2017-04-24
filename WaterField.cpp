#include "WaterField.h"

WaterField::WaterField()
{

}

BoardField *WaterField::clone() const
{
    return new WaterField;
}

void WaterField::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->fillRect(boundingRect(), QColor(Qt::blue));
}

