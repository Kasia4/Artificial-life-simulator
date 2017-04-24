#include "BoardField.h"

BoardField::BoardField()
{

}

void BoardField::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
   painter->drawRect(boundingRect());
}

QRectF BoardField::boundingRect() const
{
    return QRectF(x(), y(), size_*2, size_*2);
}

void BoardField::setSize(float size)
{
    size_ = size;
}

float BoardField::getSize() const
{
    return size_;
}

