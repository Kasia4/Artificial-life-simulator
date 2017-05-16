#include "CircleCollider.h"

CircleCollider::CircleCollider()
    :radius_(0)
{

}

CircleCollider::CircleCollider(qreal radius)
    :radius_(radius)
{

}

void CircleCollider::setRadius(qreal radius)
{
    radius_ = radius;
}

qreal CircleCollider::getRadius() const
{
    return radius_;
}
