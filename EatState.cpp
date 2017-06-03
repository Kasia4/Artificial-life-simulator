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


State* EatState::clone() const
{
    return new EatState(*this);
}

void EatState::setFactors(Specimen* specimen)
{
    specimen->setAttributesStateFactors(StateAttributeFactorMap::getInstance().getAttFactorsMap(StateType::EAT));
}

State* EatState::eat(Specimen *specimen)
{
    bool done = false;
    specimen->setMove(false);
	if(specimen->getTarget())
    {
        qreal difference = specimen->getAttributeValue(AttributeType::FOOD_NECESSITY);
        if(specimen->getSpec() == SpecimenType::HERBIVORE)
        {
            GroundField* ground = dynamic_cast<GroundField*>(specimen->getTarget());
            ground->modifyOvergrow(-difference);
            if(ground->getOvergrow() == 0)
            {
                ground->lockField();
                done = true;
            }
        }

        else
        {
            Specimen* target = dynamic_cast<Specimen*>(specimen->getTarget());
            target->setMove(false);
            target->updateHp(-difference);
            if(target->getHp() == 0)
                done = true;
        }

        qreal currentValue = specimen->getNeedValue(NeedType::EAT) - difference;
        if(currentValue <= 0)
        {
            specimen->setNeedValue(NeedType::EAT, 0);
            done = true;
        }
        else
            specimen->setNeedValue(NeedType::EAT, currentValue);
	}
	else
		done = true;

	if(done)
    {
        specimen->disableTracking();
        specimen->setInterrupted(true);
        specimen->chooseNeed();
        return new State();
    }
    return this;
}
