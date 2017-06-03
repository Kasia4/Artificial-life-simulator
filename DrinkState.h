#ifndef DRINKSTATE_H
#define DRINKSTATE_H
#include "State.h"

class DrinkState : public State
{
public:
    DrinkState();
    State* action(Specimen *specimen);
	State* clone() const;
    void setFactors(Specimen* specimen);

private:
    State* drink(Specimen* specimen);
};

#endif // DRINKSTATE_H
