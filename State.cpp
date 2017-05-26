#include "State.h"
#include "states.h"
State::State()
{

}

State* State::action(Specimen *specimen)
{
    if(specimen->getIsDead())
        return new DieState();
    else if(specimen->getIsChased()) // TODO stay in the same RunAwayState
        return new RunAwayState();
    else if(specimen->getNeedChanged())
    {
        switch(specimen->getCurrentNeed())
        {
            case NeedType::DRINK :
                return new SearchWaterState();
                break;
            case NeedType::EAT :
                return new SearchFoodState();
                break;
            case NeedType::SLEEP :
                return new SleepState();
                break;
            case NeedType::REPRODUCE :
                return new SearchPartnerState();
                break;
            case NeedType::NONE :
                return new State();
                break;
        }
    }
    return nullptr;
}
