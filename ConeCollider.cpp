#include "ConeCollider.h"

ConeCollider::ConeCollider()
    :radius_(0)
    ,apex_angle_(0)
{
    generateShape();
}

ConeCollider::ConeCollider(qreal radius, qreal apex_angle)
    :radius_(radius)
    ,apex_angle_(apex_angle)
{
    generateShape();
}

void ConeCollider::setRadius(qreal radius)
{
    radius_ = radius;
    generateShape();
}

void ConeCollider::setApexAngle(qreal apex_angle)
{
    apex_angle_ = apex_angle;
    generateShape();
}

qreal ConeCollider::getRadius() const
{
    return radius_;
}

qreal ConeCollider::getApexAngle() const
{
    return apex_angle_;
}

void ConeCollider::generateShape()
{
    shape_.arcTo(QRectF(-radius_,-radius_,radius_*2, radius_*2),-apex_angle_/2, apex_angle_);
}

QRectF CircleCollider::boundingRect() const
{
    return QRectF(-radius_,-radius_,radius_*2,radius_*2);
}
