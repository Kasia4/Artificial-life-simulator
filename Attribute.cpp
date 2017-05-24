#include "Attribute.h"

Attribute::Attribute()
{

}

Attribute::Attribute(qreal base, qreal factor) : base_(base), factor_(factor)
{

}

qreal Attribute::getValue() const
{
    return base_ * factor_;

}

void Attribute::setFactor(const qreal &factor)
{
    factor_ = factor;
}

qreal Attribute::getFactor() const
{
    return factor_;
}
