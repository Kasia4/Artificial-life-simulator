#include "Attribute.h"

Attribute::Attribute()
{

}

Attribute::Attribute(qreal base, qreal state_factor, qreal need_factor)
  :base_(base)
  ,state_factor_(state_factor)
  ,need_factor_(need_factor)
{

}

qreal Attribute::getValue() const
{
	return base_ * state_factor_ * need_factor_;

}

qreal Attribute::getStateFactor() const
{
	return state_factor_;
}

void Attribute::setStateFactor(const qreal& state_factor)
{
	state_factor_ = state_factor;
}

qreal Attribute::getNeedFactor() const
{
	return need_factor_;
}

void Attribute::setNeedFactor(const qreal& need_factor)
{
	need_factor_ = need_factor;
}

qreal Attribute::getBase() const
{
    return base_;
}

void Attribute::setBase(const qreal& base)
{
    base_ = base;
}

