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
       specimen->setTarget(nearestWater(specimen));
    if(specimen->getCaughtTarget())
       return new DrinkState();
    return this;
}

WaterField *SearchWaterState::nearestWater(Specimen *specimen)
{
    specimen->nearestField(FieldType::WATER);
}
