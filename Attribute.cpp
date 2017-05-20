#include "Attribute.h"

Attribute::Attribute()
{

}

Attribute::Attribute(qreal base, qreal factor) : base(base), factor(factor)
{

}

qreal Attribute::getValue()
{
    return base * factor;

}
