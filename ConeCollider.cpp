#include "ConeCollider.h"

ConeCollider::ConeCollider()
    :radius_(0)
    ,apex_angle_(0)
{

}

ConeCollider::ConeCollider(qreal radius, qreal apex_angle)
    :radius_(radius)
    ,apex_angle_(apex_angle)
{

}

void ConeCollider::setRadius(qreal radius)
{
    radius_ = radius;
}

void ConeCollider::setApexAngle(qreal apex_angle)
{
    apex_angle_ = apex_angle;
}

qreal ConeCollider::getRadius() const
{
    return radius_;
}

qreal ConeCollider::getApexAngle() const
{
    return apex_angle_;
}

