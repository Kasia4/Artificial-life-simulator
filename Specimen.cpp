#include "Specimen.h"

Specimen::Specimen()
{

}


QRectF Specimen::boundingRect() const
{
    return QRectF(x() - size_, y() - size_, size_*2, size_*2);

}

void Specimen::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawEllipse(boundingRect());
}

void Specimen::setSize(float size)
{
    size_=size;
}

float Specimen::getSize() const
{
    return size_;
}
