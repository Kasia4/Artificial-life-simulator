#include "RunAwayState.h"

RunAwayState::RunAwayState()
{

}

State* RunAwayState::action(Specimen *specimen)
{

    State* result = State::action(specimen);
    if(result)
       return result;
    return runAway(specimen);

}

State *RunAwayState::runAway(Specimen *specimen)
{
    if(specimen->getEscapedFromChaser())
    {
        specimen->setIsChased(false);
        specimen->setChaser(nullptr);
        return new State();
    }
    return this;

}
