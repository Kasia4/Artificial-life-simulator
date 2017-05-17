#include "BoardField.h"

BoardField::BoardField()
{

}

int BoardField::type() const
{
    return ItemType :: FIELD;

}

void BoardField::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
   painter->drawRect(boundingRect());
}

QRectF BoardField::boundingRect() const
{
    return QRectF(0,0, size_, size_);
}

void BoardField::setSize(qreal size)
{
    size_ = size;
}

qreal BoardField::getSize() const
{
    return size_;
}

