#include "SearchFoodState.h"

SearchFoodState::SearchFoodState()
{

}

State* SearchFoodState::action(Specimen *specimen)
{
    State* result = State::action(specimen);
    if(result)
       return result;
	return searchForFood(specimen);
}

void SearchFoodState::setFactors(Specimen* specimen)
{
	specimen->setAttributesStateFactors(StateAttributeFactorMap::getInstance().getAttFactorsMap(StateType::SEARCH_FOOD));

}

State* SearchFoodState::clone() const
{
	return new SearchFoodState(*this);
}

State* SearchFoodState::searchForFood(Specimen *specimen)
{
    specimen->setMove(true);
	SimulationObject* nearest_food = nearestFood(specimen);
    if(!specimen->getTarget() || specimen->getTarget() != nearest_food)
    {
        specimen->disableTracking();
        specimen->setTarget(nearest_food);
    }

    if(specimen->getCaughtTarget())
       return new EatState();
    return this;
}




SimulationObject *SearchFoodState::nearestFood(Specimen *specimen)
{
    if(specimen->getSpec() == SpecimenType::HERBIVORE)
    {
        return specimen->nearestField(FieldType::GROUND);
    }

    return specimen->nearestSpecimen(SpecimenType::HERBIVORE);

}
