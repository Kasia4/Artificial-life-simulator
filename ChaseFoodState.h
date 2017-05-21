#ifndef CHASEFOODSTATE_H
#define CHASEFOODSTATE_H
#include "State.h"

class ChaseFoodState : public State
{
public:
    ChaseFoodState();
    void action(Specimen *specimen);
private:
    void chaseForFood();
};

#endif // CHASEFOODSTATE_H
