#ifndef CIRCLECOLLIDER_H
#define CIRCLECOLLIDER_H
#include "Collider.h"

class CircleCollider : public Collider
{
public:
    CircleCollider();
    CircleCollider(qreal radius);

    void setRadius(qreal radius);

    qreal getRadius() const;
private:
    qreal radius_;
};

#endif // CIRCLECOLLIDER_H
