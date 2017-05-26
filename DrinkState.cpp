#include "DrinkState.h"

DrinkState::DrinkState()
{

}

State* DrinkState::action(Specimen *specimen)
{
    State* result = State::action(specimen);
    if(result)
       return result;
    return drink(specimen);
}

State *DrinkState::drink(Specimen *specimen)
{

}
