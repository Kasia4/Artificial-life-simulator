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

State* DrinkState::clone() const
{
    return new DrinkState(*this);
}

void DrinkState::setFactors(Specimen* specimen)
{
    specimen->setAttributesStateFactors(StateAttributeFactorMap::getInstance().getAttFactorsMap(StateType::DRINK));

}

State *DrinkState::drink(Specimen *specimen)
{
    specimen->setMove(false);
	qreal value = specimen->getNeedValue(NeedType::DRINK) - specimen->getAttributeValue(AttributeType::STRENGTH);
    if(value < 0)
    {
        specimen->setNeedValue(NeedType::DRINK, 0);
        specimen->disableTracking();
		specimen->chooseNeed();
        return new State();
    }
    else
        specimen->setNeedValue(NeedType::DRINK, value);
    return this;
}
