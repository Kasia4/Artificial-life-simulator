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

void RunAwayState::setFactors(Specimen* specimen)
{
    specimen->setAttributesStateFactors(StateAttributeFactorMap::getInstance().getAttFactorsMap(StateType::RUN_AWAY));

}

State* RunAwayState::runAway(Specimen *specimen)
{
    specimen->setMove(true);
    if(specimen->getEscapedFromChaser())
    {
		specimen->setIsChased(false);
        specimen->setChaser(nullptr);
		specimen->chooseNeed();
        specimen->setInterrupted(true);
        return new State();
    }
    return this;

}
