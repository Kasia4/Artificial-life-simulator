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

State *SearchWaterState::searchForWater(Specimen *specimen)
{

    if(!specimen->getTarget() || specimen->getTarget() != nearestWater(specimen))
    {
        specimen->disableTracking();
        specimen->setTarget(nearestWater(specimen));
    }
    if(specimen->getCaughtTarget())
       return new DrinkState();
    return this;
}

BoardField* SearchWaterState::nearestWater(Specimen *specimen)
{
    return specimen->nearestField(FieldType::WATER);
}
