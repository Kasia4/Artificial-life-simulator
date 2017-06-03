#include "SearchWaterState.h"

SearchWaterState::SearchWaterState()
{

}

State* SearchWaterState::action(Specimen *specimen)
{

    State* result = State::action(specimen);
    if(result)
       return result;
	return searchForWater(specimen);
}

State* SearchWaterState::clone() const
{
    return new SearchWaterState(*this);
}

void SearchWaterState::setFactors(Specimen* specimen)
{
    specimen->setAttributesStateFactors(StateAttributeFactorMap::getInstance().getAttFactorsMap(StateType::SEARCH_WATER));

}

State *SearchWaterState::searchForWater(Specimen *specimen)
{
    specimen->setMove(true);
    BoardField* nearest_water = nearestWater(specimen);
    if(!specimen->getTarget() || specimen->getTarget() != nearest_water)
    {
        specimen->disableTracking();
        specimen->setTarget(nearest_water);
    }
    if(specimen->getCaughtTarget())
       return new DrinkState();
    return this;
}

BoardField* SearchWaterState::nearestWater(Specimen *specimen)
{
    return specimen->nearestField(FieldType::WATER);
}
