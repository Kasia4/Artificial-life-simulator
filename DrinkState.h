#ifndef DRINKSTATE_H
#define DRINKSTATE_H
#include "State.h"

class DrinkState : public State
{
public:
    DrinkState();
    State* action(Specimen *specimen);
private:
    void drink();
};

#endif // DRINKSTATE_H
