#include "State.h"
#include "states.h"
State::State()
{

}

void State::action(Specimen *specimen)
{
     if(specimen->getHp() < 0)
        specimen->setCurrentState(new DieState);
}
