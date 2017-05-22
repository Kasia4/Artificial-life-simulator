#include "BarrenField.h"

BarrenField::BarrenField()
{

}

BoardField *BarrenField::clone() const
{
    BarrenField* temp = new BarrenField;
    return temp;
}


void BarrenField::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->fillRect(boundingRect(), QColor(Qt::lightGray));
}
