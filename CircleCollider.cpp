#include "CircleCollider.h"

CircleCollider::CircleCollider()
    :radius_(0)
{
    generateShape();
}

CircleCollider::CircleCollider(qreal radius)
    :radius_(radius)
{
    generateShape();
}

void CircleCollider::setRadius(qreal radius)
{
    radius_ = radius;
    generateShape();
}

qreal CircleCollider::getRadius() const
{
    return radius_;
}

void CircleCollider::generateShape()
{
    //TODO czyszczenie przy zmianie
    shape_.addEllipse(QPointF(0,0), radius_, radius_);
}

QRectF CircleCollider::boundingRect() const
{
    return QRectF(-radius_,-radius_,radius_*2,radius_*2);
}
