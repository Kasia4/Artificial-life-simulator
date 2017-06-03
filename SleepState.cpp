#include "SleepState.h"

SleepState::SleepState()
{

}

State* SleepState::action(Specimen *specimen)
{

    State* result = State::action(specimen);
    if(result)
       return result;
	return sleep(specimen);
}

void SleepState::setFactors(Specimen* specimen)
{
	specimen->setAttributesStateFactors(StateAttributeFactorMap::getInstance().getAttFactorsMap(StateType::SLEEP));
}

State* SleepState::clone() const
{
	return new SleepState(*this);
}

State *SleepState::sleep(Specimen *specimen)
{
    specimen->setMove(false);
	qreal value = specimen->getNeedValue(NeedType::SLEEP) - specimen->getAttributeValue(AttributeType::STRENGTH);
    if(value <= 0)
    {
        specimen->setNeedValue(NeedType::SLEEP, 0);
		specimen->chooseNeed();

        return new State();
    }
    else
        specimen->setNeedValue(NeedType::SLEEP, value);
    return this;

}
