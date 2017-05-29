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
        specimen->setNeedChanged(false);
        switch(specimen->getCurrentNeed())
        {
            case NeedType::EAT :
                std::cout<<"szukac jedzenia ";
                return new SearchFoodState();
                break;
            case NeedType::DRINK :
                std::cout<<"szukac wody ";
                return new SearchWaterState();
                break;
            case NeedType::SLEEP :
                std::cout<<"spac ";
                return new SleepState();
                break;
            case NeedType::REPRODUCE :                
                std::cout<<"szukac kogos ";
                return new SearchPartnerState();
                break;
            case NeedType::NONE :                
                std::cout<<"nic ";
                return new State();
                break;
        }
    }
    return nullptr;
}
