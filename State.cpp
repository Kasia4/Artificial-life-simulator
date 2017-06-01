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
    if(specimen->getIsChased()) // TODO stay in the same RunAwayState
    {
        std::cout<<"sledzi ";
        specimen->setInterrupted(true);
        return new RunAwayState();
    }
    else if(specimen->getNeedChanged() || specimen->getInterrupted())
    {
        specimen->setMove(true);
        specimen->setTarget(nullptr);
        specimen->setNeedChanged(false);
        specimen->setInterrupted(false);
        std::cout<<"zmiana ";
		return StateFactory::getInstance().createByNeed(specimen->getCurrentNeed());

    }
    return nullptr;
}
