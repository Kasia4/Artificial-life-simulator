#include "State.h"
#include "states.h"
State::State()
{

}

State* State::action(Specimen *specimen)
{
    if(specimen->getIsDead())
        return new DieState();
    else if(specimen->getIsChased())
        return new RunAwayState();
}
