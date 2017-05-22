#ifndef RUNAWAYSTATE_H
#define RUNAWAYSTATE_H
#include "State.h"

class RunAwayState : public State
{
public:
    RunAwayState();
    void action(Specimen* specimen);
private:
    void runAway(Specimen* specimen);
};

#endif // RUNAWAYSTATE_H