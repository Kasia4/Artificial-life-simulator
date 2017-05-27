#include "FocusRing.h"

FocusRing::FocusRing()
{
    pen_.setStyle(Qt::DotLine);
    pen_.setWidth(3);
    setOpacity(0.4);
}

qreal FocusRing::radius() const
{
    return radius_;
}

void FocusRing::setRadius(const qreal &radius)
{
    radius_ = radius;
}

QPen FocusRing::pen() const
{
    return pen_;
}

void FocusRing::setPen(const QPen &pen)
{
    pen_ = pen;
}

QRectF FocusRing::boundingRect() const
{
    return QRectF(-radius_, -radius_, radius_*2, radius_*2);
}

void FocusRing::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(pen_);
    painter->setBrush(Qt::NoBrush);
    painter->drawEllipse(QPointF(0,0), radius_, radius_);
}
