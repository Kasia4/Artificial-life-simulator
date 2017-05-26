#include "ChaseFoodState.h"

ChaseFoodState::ChaseFoodState()
{

}
State* ChaseFoodState::action(Specimen *specimen)
{
    State* result = State::action(specimen);
    if(result)
       return result;
    return chaseFood(specimen);
}

State *ChaseFoodState::chaseFood(Specimen *specimen)
{

}
