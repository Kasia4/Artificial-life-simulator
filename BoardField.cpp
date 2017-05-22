#include "BoardField.h"

BoardField::BoardField()
{

}

BoardField::BoardField(const QPoint &position)
    :position_ (position)
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

QPoint BoardField::getPosition() const
{
    return position_;
}

void BoardField::setPosition(const QPoint &position)
{
    position_ = position;
}

