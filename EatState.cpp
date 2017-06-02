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

State* EatState::eat(Specimen *specimen)
{
    bool done = false;
    specimen->setMove(false);
    qreal difference = specimen->getAttributeValue(AttributeType::FOOD_NECESSITY);
    if(specimen->getSpec() == SpecimenType::HERBIVORE)
    {
        GroundField* ground = dynamic_cast<GroundField*>(specimen->getTarget());
        ground->modifyOvergrow(-difference);
		if(ground->getOvergrow() == 0)
		{
            ground->lockField();
//			specimen->disableTracking();
//			specimen->setInterrupted(true);
//			specimen->chooseNeed();
//            return new State();
            done = true;
        }
	}
	else
	{
		Specimen* target = dynamic_cast<Specimen*>(specimen->getTarget());
		target->setMove(false);
		target->updateHp(-difference);
		if(target->getHp() == 0)
        {
//			specimen->disableTracking();
//			specimen->setInterrupted(true);
//			specimen->chooseNeed();
//            return new State();
            done = true;
		}
	}
	// TODO update hp or overgrowing level of target without dynamic_cast
	qreal currentValue = specimen->getNeedValue(NeedType::EAT) - difference;
	if(currentValue <= 0)
	{
		specimen->setNeedValue(NeedType::EAT, 0);

//        specimen->disableTracking();
//		specimen->chooseNeed();
//        return new State();
        done = true;
    }
    else
	specimen->setNeedValue(NeedType::EAT, currentValue);
    if(done)
    {
        specimen->disableTracking();
        specimen->setInterrupted(true);
        specimen->chooseNeed();
        return new State();
    }
    return this;


}
