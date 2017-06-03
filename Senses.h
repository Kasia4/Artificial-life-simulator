#ifndef SENSES_H
#define SENSES_H

#include "Collider.h"

class Senses : public Collider
{
public:
    Senses();
    void addSense(Collider* collider);
    void removeSense(Collider* collider);
    QRectF boundingRect() const;

protected:
    virtual void generateShape();

private:
    QList<Collider*> senses_;

};

#endif // SENSES_H
