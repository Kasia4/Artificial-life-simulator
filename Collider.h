#ifndef COLLIDER_H
#define COLLIDER_H
#include <QGraphicsItem>
#include "ItemType.h"

class Collider : public QGraphicsItem
{
public:
    Collider();
    int type() const;
};

#endif // COLLIDER_H
