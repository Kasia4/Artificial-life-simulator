#include "Border.h"
Border::Border(QPointF topLeft, QPointF topRight, QPointF bottomLeft, QPointF bottomRight)
{
    topLine = new QLineF(topLeft, topRight);
    leftLine = new QLineF(topLeft, bottomLeft);
    rightLine = new QLineF(topRight, bottomRight);
    bottomLine = new QLineF(bottomLeft, bottomRight);

}

void Border::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(painter);
    Q_UNUSED(option);
    Q_UNUSED(widget);

}

QRectF Border::boundingRect() const
{
    return QRectF(0, 0, 2, 2);
}



int Border::type() const
{
    return ItemType::BORDER;

}

QLineF *Border::getTopLine() const
{
    return topLine;
}

void Border::setTopLine(QLineF *value)
{
    topLine = value;
}

QLineF *Border::getLeftLine() const
{
    return leftLine;
}

void Border::setLeftLine(QLineF *value)
{
    leftLine = value;
}

QLineF *Border::getRightLine() const
{
    return rightLine;
}

void Border::setRightLine(QLineF *value)
{
    rightLine = value;
}

QLineF *Border::getBottomLine() const
{
    return bottomLine;
}

void Border::setBottomLine(QLineF *value)
{
    bottomLine = value;
}
