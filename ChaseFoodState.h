#ifndef CHASEFOODSTATE_H
#define CHASEFOODSTATE_H
#include "State.h"

class ChaseFoodState : public State
{
public:
    ChaseFoodState();
    State* action(Specimen *specimen);
private:
    State* chaseFood(Specimen* specimen);
};

#endif // CHASEFOODSTATE_H
