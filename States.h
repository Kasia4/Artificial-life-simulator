#ifndef STATES_H
#define STATES_H

#include "DrinkState.h"
#include "EatState.h"
#include "ReproduceState.h"
#include "SearchFoodState.h"
#include "SearchPartnerState.h"
#include "SearchWaterState.h"
#include "RunAwayState.h"
#include "SleepState.h"

enum class StateType : unsigned
{
	BASIC,
	DRINK,
	EAT,
	REPRODUCE,
	SEARCH_FOOD,
	SEARCH_PARTNER,
	SEARCH_WATER,
	RUN_AWAY,
	SLEEP
};

#endif // STATES_H
