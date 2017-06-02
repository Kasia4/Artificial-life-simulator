#include "StateAttributeFactorMap.h"

StateAttributeFactorMap::StateAttributeFactorMap()
{

}

StateAttributeFactorMap& StateAttributeFactorMap::getInstance()
{
	static StateAttributeFactorMap instance;
	return instance;
}

void StateAttributeFactorMap::setFactor(StateType state, AttributeType attribute, qreal value)
{
	map_[state][attribute] = value;
}

void StateAttributeFactorMap::setAttFactorsMap(StateType state, const AttFactorsMap& att_map)
{
	map_[state] = att_map;
}

qreal StateAttributeFactorMap::getFactor(StateType state, AttributeType attribute) const
{
	return map_[state][attribute];
}

const AttFactorsMap& StateAttributeFactorMap::getAttFactorsMap(StateType state) const
{
	return map_[state];
}

const StateFactorsMap& StateAttributeFactorMap::map()
{
	return map_;
}



