#include "EatState.h"

EatState::EatState()
{

}

State* EatState::action(Specimen *specimen)
{
    State* result = State::action(specimen);
    if(result)
       return result;
    return eat(specimen);
}

State *EatState::eat(Specimen *specimen)
{

}
