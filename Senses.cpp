#include "Senses.h"

Senses::Senses()
{

}

void Senses::addSense(Collider *collider)
{
    senses_.append(collider);
}

void Senses::removeSense(Collider *collider)
{
    senses_.removeAll(collider);
}

QRectF Senses::boundingRect() const
{
    return shape_.controlPointRect();
}



void Senses::generateShape()
{
    shape_ = QPainterPath();
    for(Collider* coll : senses_)
    {
        shape_.addPath(coll->shape());
    }
}
