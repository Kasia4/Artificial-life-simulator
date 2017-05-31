#include "StateFactory.h"

StateFactory::StateFactory()
{
	registerState(StateType::BASIC, new State);
	registerState(StateType::DRINK, new DrinkState);
	registerState(StateType::EAT, new EatState);
	registerState(StateType::REPRODUCE, new ReproduceState);
	registerState(StateType::SEARCH_FOOD, new SearchFoodState);
	registerState(StateType::SEARCH_PARTNER, new SearchPartnerState);
	registerState(StateType::SEARCH_WATER, new SearchWaterState);
}

StateFactory& StateFactory::getInstance()
{
	static StateFactory instance;
	return instance;
}

void StateFactory::registerState(StateType type, State *state)
{
	prototypes_.insert(type, state);
}

State* StateFactory::create(StateType type)
{
	return prototypes_.value(type)->clone();
}

StateFactory::~StateFactory()
{
	for(auto spec : prototypes_.values())
	{
		delete spec;
	}
}
