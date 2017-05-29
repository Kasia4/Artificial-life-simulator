#include "Attribute.h"

Attribute::Attribute()
{

}

Attribute::Attribute(qreal base, qreal factor_state, qreal factor_need)
  :base_(base)
  ,factor_state_(factor_state)
  ,factor_need_(factor_need)
{

}

qreal Attribute::getValue() const
{
    return base_ * factor_state_ * factor_need_;

}

qreal Attribute::getFactor_state() const
{
    return factor_state_;
}

void Attribute::setFactor_state(const qreal& factor_state)
{
    factor_state_ = factor_state;
}

qreal Attribute::getFactor_need() const
{
    return factor_need_;
}

void Attribute::setFactor_need(const qreal& factor_need)
{
    factor_need_ = factor_need;
}

qreal Attribute::getBase() const
{
    return base_;
}

void Attribute::setBase(const qreal& base)
{
    base_ = base;
}

