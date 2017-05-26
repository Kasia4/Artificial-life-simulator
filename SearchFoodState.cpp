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

State *SearchFoodState::searchForFood(Specimen *specimen)
{

}
