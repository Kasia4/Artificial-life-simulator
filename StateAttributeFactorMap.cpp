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

    map_[StateType::SLEEP].insert(AttributeType::FOOD_NECESSITY, 0.8);
    map_[StateType::SLEEP].insert(AttributeType::WATER_NECESSITY, 0.8);
    map_[StateType::REPRODUCE].insert(AttributeType::FOOD_NECESSITY, 1.1);
    map_[StateType::REPRODUCE].insert(AttributeType::WATER_NECESSITY, 1.1);
    map_[StateType::REPRODUCE].insert(AttributeType::SLEEP_NECESSITY, 1.1);
    map_[StateType::RUN_AWAY].insert(AttributeType::FOOD_NECESSITY, 1.25);
    map_[StateType::RUN_AWAY].insert(AttributeType::WATER_NECESSITY, 1.25);
    map_[StateType::RUN_AWAY].insert(AttributeType::SLEEP_NECESSITY, 1.25);
    map_[StateType::SEARCH_FOOD].insert(AttributeType::FOOD_NECESSITY, 1.2);
    map_[StateType::SEARCH_FOOD].insert(AttributeType::WATER_NECESSITY, 1.2);
    map_[StateType::SEARCH_FOOD].insert(AttributeType::SLEEP_NECESSITY, 1.2);
    map_[StateType::SEARCH_WATER].insert(AttributeType::FOOD_NECESSITY, 1.2);
    map_[StateType::SEARCH_WATER].insert(AttributeType::WATER_NECESSITY, 1.2);
    map_[StateType::SEARCH_WATER].insert(AttributeType::SLEEP_NECESSITY, 1.2);
    map_[StateType::SEARCH_PARTNER].insert(AttributeType::FOOD_NECESSITY, 1.15);
    map_[StateType::SEARCH_PARTNER].insert(AttributeType::WATER_NECESSITY, 1.15);
    map_[StateType::SEARCH_PARTNER].insert(AttributeType::SLEEP_NECESSITY, 1.15);


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



