#include "Collider.h"

Collider::Collider()
{
    setOpacity(0);
}

int Collider::type() const
{
    return ItemType :: COLLIDER;
}
