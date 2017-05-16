#ifndef COLLIDER_H
#define COLLIDER_H
#include <QGraphicsItem>
#include "ItemType.h"

class Collider : public QGraphicsItem
{
public:
    Collider();
    int type() const;
private:
    virtual QPainterPath getShape() = 0;
};

#endif // COLLIDER_H
