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

State *SleepState::sleep(Specimen *specimen)
{
    qreal value = specimen->getNeedValue(NeedType::SLEEP) - specimen->getAttributeValue(AttributeType::SLEEP_NECESSITY);
    if(value < 0)
        specimen->setNeedValue(NeedType::SLEEP, 0);
    else
        specimen->setNeedValue(NeedType::SLEEP, value);
    return new SleepState();

}
