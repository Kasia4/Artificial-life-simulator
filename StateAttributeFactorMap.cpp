#include "StateAttributeFactorMap.h"

StateAttributeFactorMap::StateAttributeFactorMap()
{
	map_.insert(StateType::BASIC, AttFactorsMap());
	map_.insert(StateType::DRINK, AttFactorsMap());
	map_.insert(StateType::EAT, AttFactorsMap());
	map_.insert(StateType::REPRODUCE, AttFactorsMap());
	map_.insert(StateType::RUN_AWAY, AttFactorsMap());
	map_.insert(StateType::SEARCH_FOOD, AttFactorsMap());
	map_.insert(StateType::SEARCH_PARTNER, AttFactorsMap());
	map_.insert(StateType::SEARCH_WATER, AttFactorsMap());
	map_.insert(StateType::SLEEP, AttFactorsMap());

	map_[StateType::SLEEP].insert(AttributeType::FOOD_NECESSITY, 0.7);
	map_[StateType::SLEEP].insert(AttributeType::WATER_NECESSITY, 0.7);
	map_[StateType::SLEEP].insert(AttributeType::SIGHT_RANGE, 0);
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
	return map_[state].value(attribute, 1);
}

const AttFactorsMap StateAttributeFactorMap::getAttFactorsMap(StateType state) const
{
	return map_[state];
}

const StateFactorsMap& StateAttributeFactorMap::map()
{
	return map_;
}



