#include "State.h"
#include "StateFactory.h"

State::State()
{

}

State* State::clone() const
{
	return new State;
}

State* State::action(Specimen *specimen)
{
    //specimen->setMove(true);
//    if(specimen->getIsDead())
//        return new DieState();
   /* else*/ if(specimen->getIsChased()) // TODO stay in the same RunAwayState
        return new RunAwayState();
    else if(specimen->getNeedChanged())
    {
        specimen->setTarget(nullptr);
        specimen->setNeedChanged(false);
		return StateFactory::getInstance().createByNeed(specimen->getCurrentNeed());

//        switch(specimen->getCurrentNeed())
//        {
//            case NeedType::EAT :
//                return new SearchFoodState();
//                break;
//            case NeedType::DRINK :
//                return new SearchWaterState();
//                break;
//            case NeedType::SLEEP :
//                return new SleepState();
//                break;
//			case NeedType::REPRODUCE :
//                return new SearchPartnerState();
//                break;
//            case NeedType::NONE :
//                return new State();
//                break;
//        }
    }
    return nullptr;
}
