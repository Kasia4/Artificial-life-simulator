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
    std::cout<<"szukam wody ";
    std::cout<<specimen->getTarget()<<"\t";
    if(!specimen->getTarget() || specimen->getTarget() != nearestWater(specimen))
    {
        specimen->disableTracking();
        specimen->setTarget(nearestWater(specimen));
        std::cout<<specimen->getTarget()<<"\t";
    }
    if(specimen->getCaughtTarget())
       return new DrinkState();
    return this;
}

BoardField* SearchWaterState::nearestWater(Specimen *specimen)
{
    std::cout<<specimen->nearestField(FieldType::WATER)<<"\t";
    return specimen->nearestField(FieldType::WATER);
}
