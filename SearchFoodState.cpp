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

State* SearchFoodState::clone() const
{
	return new SearchFoodState(*this);
}

State* SearchFoodState::searchForFood(Specimen *specimen)
{
    specimen->setMove(true);
    QGraphicsItem* nearest_food = nearestFood(specimen);
    if(!specimen->getTarget() || specimen->getTarget() != nearest_food)
    {
        specimen->disableTracking();
        specimen->setTarget(nearest_food);
    }

    if(specimen->getCaughtTarget() /*&& specimen->getTarget()->scene()*/)
       return new EatState();
    return this;
}




QGraphicsItem *SearchFoodState::nearestFood(Specimen *specimen)
{
    if(specimen->getSpec() == SpecimenType::HERBIVORE)
    {
        return specimen->nearestField(FieldType::GROUND);
    }

    return specimen->nearestSpecimen(SpecimenType::HERBIVORE);

}
