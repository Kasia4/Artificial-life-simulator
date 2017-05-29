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

State* SearchFoodState::searchForFood(Specimen *specimen)
{
    if(!specimen->getTarget() || specimen->getTarget() != nearestFood(specimen))
    {
        specimen->disableTracking();
        specimen->setTarget(nearestFood(specimen));
    }

    if(specimen->getCaughtTarget())
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
