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
//    specimen->setMove(false);
    qreal difference = specimen->getAttributeValue(AttributeType::FOOD_NECESSITY);
    if(specimen->getSpec() == SpecimenType::HERBIVORE)
    {
        GroundField* ground = dynamic_cast<GroundField*>(specimen->getTarget());
        ground->modifyOvergrow(-difference);
    }
    else
    {
        Specimen* target = dynamic_cast<Specimen*>(specimen->getTarget());
        target->updateHp(-difference);
    }
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
