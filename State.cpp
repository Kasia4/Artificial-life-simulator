#include "State.h"
#include "StateFactory.h"

State::State()
{

}

void State::setFactors(Specimen* specimen)
{
	specimen->setAttributesStateFactors(StateAttributeFactorMap::getInstance().getAttFactorsMap(StateType::BASIC));
}

State* State::clone() const
{
    return new State(*this);
}

State* State::action(Specimen *specimen)
{
	setFactors(specimen);
	if(specimen->getIsChased())
    {
        specimen->setInterrupted(true);
        return new RunAwayState();
    }
    else if(specimen->getNeedChanged() || specimen->getInterrupted())
    {
        specimen->setMove(true);
        specimen->disableTracking();
        specimen->setNeedChanged(false);
        specimen->setInterrupted(false);
		return StateFactory::getInstance().createByNeed(specimen->getCurrentNeed());

    }
    return nullptr;
}
