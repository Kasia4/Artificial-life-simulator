#include "SleepState.h"

SleepState::SleepState()
{

}

State* SleepState::action(Specimen *specimen)
{
    sleep(specimen);
}

void SleepState::sleep(Specimen *specimen)
{
    qreal value = specimen->getTiredness() - specimen->getAttributeValue(AttributeType::SLEEPING_NECESSITY);
    if(value < 0)
        specimen->setTiredness(0);
    else
        specimen->setTiredness(value);


}
