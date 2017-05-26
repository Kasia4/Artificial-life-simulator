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

}
