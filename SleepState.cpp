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

State* SleepState::clone() const
{
	return new SleepState(*this);
}

State *SleepState::sleep(Specimen *specimen)
{
    specimen->setMove(false);
    qreal value = specimen->getNeedValue(NeedType::SLEEP) - specimen->getAttributeValue(AttributeType::SLEEP_NECESSITY);
    if(value <= 0)
    {
        specimen->setNeedValue(NeedType::SLEEP, 0);
        return new State();
    }
    else
        specimen->setNeedValue(NeedType::SLEEP, value);
    return this;

}
