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

State* RunAwayState::clone() const
{
	return new RunAwayState(*this);
}

State* RunAwayState::runAway(Specimen *specimen)
{
    specimen->setMove(true);
    if(specimen->getEscapedFromChaser())
    {
        specimen->setIsChased(false);
        specimen->setChaser(nullptr);
//        specimen->setInterrupted(true);
        return new State();
    }
    return this;

}
