#include "DrinkState.h"

DrinkState::DrinkState()
{

}

State* DrinkState::action(Specimen *specimen)
{
    State* result = State::action(specimen);
    if(result)
       return result;
    return drink(specimen);
}

State *DrinkState::drink(Specimen *specimen)
{
    qreal value = specimen->getNeedValue(NeedType::DRINK) - specimen->getAttributeValue(AttributeType::WATER_NECESSITY);
    if(value < 0)
    {
        specimen->setNeedValue(NeedType::DRINK, 0);
        return new State();
    }
    else
        specimen->setNeedValue(NeedType::DRINK, value);
    return this;
}
