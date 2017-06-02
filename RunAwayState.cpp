#include "RunAwayState.h"

RunAwayState::RunAwayState()
{

}

State* RunAwayState::action(Specimen *specimen)
{

    return runAway(specimen);

}

State* RunAwayState::clone() const
{
	return new RunAwayState(*this);
}

State* RunAwayState::runAway(Specimen *specimen)
{
    std::cout<<"uciekam ";
    specimen->setMove(true);
    if(specimen->getEscapedFromChaser())
    {
		specimen->setIsChased(false);
        specimen->setChaser(nullptr);
		specimen->chooseNeed();
//        specimen->setInterrupted(true);
        return new State();
    }
    return this;

}
