#ifndef RUNAWAYSTATE_H
#define RUNAWAYSTATE_H
#include "State.h"

class RunAwayState : public State
{
public:
    RunAwayState();
    State* action(Specimen* specimen);
private:
    void runAway(Specimen* specimen);
};

#endif // RUNAWAYSTATE_H
