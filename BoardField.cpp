#include "BoardField.h"

BoardField::BoardField()
{
	setFlags(QGraphicsItem::ItemIsSelectable);
	setZValue(0);
}

BoardField::BoardField(const QPoint &position)
    :position_ (position)
{

}

QRectF BoardField::fieldRect() const
{
    return QRectF(0,0, size_, size_);
}


int BoardField::type() const
{
    return ItemType :: FIELD;

}

void BoardField::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->fillRect(fieldRect(), getColor());
    if(isSelected())
    {
        QPainterPath selection_path;
        selection_path.addRect(fieldRect() + QMargins(-2,-2,-2,-2));
        QPen selection_pen(Qt::DotLine);
        selection_pen.setWidth(3);
        painter->setPen(selection_pen);
        painter->drawPath(selection_path);
    }
}

QRectF BoardField::boundingRect() const
{
    return QRectF(0,0, size_+1, size_+1);
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

