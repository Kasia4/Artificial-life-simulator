#include "State.h"
#include "StateFactory.h"

State::State()
{

}

State* State::clone() const
{
	return new State;
}

State* State::action(Specimen *specimen)
{
    //specimen->setMove(true);
//    if(specimen->getIsDead())
//        return new DieState();
   /* else*/ if(specimen->getIsChased()) // TODO stay in the same RunAwayState
        return new RunAwayState();
    else if(specimen->getNeedChanged() || specimen->getInterrupted())
    {
        specimen->setTarget(nullptr);
        specimen->setNeedChanged(false);
        specimen->setInterrupted(false);
		return StateFactory::getInstance().createByNeed(specimen->getCurrentNeed());

    }
    return nullptr;
}
