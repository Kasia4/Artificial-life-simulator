#ifndef CHASEFOODSTATE_H
#define CHASEFOODSTATE_H
#include "State.h"

class ChaseFoodState : public State
{
public:
    ChaseFoodState();
    State* action(Specimen *specimen);
private:
    void chaseForFood();
};

#endif // CHASEFOODSTATE_H
