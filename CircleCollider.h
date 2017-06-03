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
    virtual void generateShape();
    QRectF boundingRect() const;

private:
    qreal radius_;

};

#endif // CIRCLECOLLIDER_H
