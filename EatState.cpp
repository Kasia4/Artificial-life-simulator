#include "EatState.h"

EatState::EatState()
{

}

State* EatState::action(Specimen *specimen)
{
    State* result = State::action(specimen);
    if(result)
       return result;
    return eat(specimen);
}

State *EatState::eat(Specimen *specimen)
{
    qreal difference = specimen->getAttributeValue(AttributeType::FOOD_NECESSITY);
//    if(specimen->getSpec() == SpecimenType::HERBIVORE)
//    {
//        G
//        specimen->getTarget()->
//    }
    // TODO update hp or overgrowing level of target without dynamic_cast
    qreal currentValue = specimen->getNeedValue(NeedType::EAT) - difference;
    if(currentValue <= 0)
    {
        specimen->setNeedValue(NeedType::EAT, 0);
        return new State();
    }

    specimen->setNeedValue(NeedType::EAT, currentValue);
    return this;

}
