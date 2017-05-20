#ifndef BEHAVIOURMANAGER_H
#define BEHAVIOURMANAGER_H
#include <states.h>

class BehaviourManager
{
public:
   static BehaviourManager& getInstance();
private:
   BehaviourManager();
   BehaviourManager(const BehaviourManager&) = delete;
   BehaviourManager& operator=(const BehaviourManager&) = delete;

   ChaseFoodState chaseFoodState_;
   DieState dieState_;
   DrinkState drinkState_;
   EatState eatState_;
   ReproduceState reproduceState_;
   SearchFoodState searchFoodState_;
   SearchPartnerState searchPartnerState_;
   SearchWaterState searchWaterState_;
   SleepState sleepState_;
};

#endif // BEHAVIOURMANAGER_H
