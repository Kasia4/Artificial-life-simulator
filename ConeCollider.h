#ifndef CONECOLLIDER_H
#define CONECOLLIDER_H
#include "Collider.h"

class ConeCollider : public Collider
{
public:
    ConeCollider();
    ConeCollider(qreal radius, qreal apex_angle);

    void setRadius(qreal radius);
    void setApexAngle(qreal apex_angle);

    qreal getRadius() const;
    qreal getApexAngle() const;
private:
    qreal radius_;
    qreal apex_angle_;
};

#endif // CONECOLLIDER_H
