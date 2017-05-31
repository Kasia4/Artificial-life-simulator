#ifndef RUNAWAYSTATE_H
#define RUNAWAYSTATE_H
#include "State.h"

class RunAwayState : public State
{
public:
    RunAwayState();
    State* action(Specimen* specimen);
	State* clone() const;
private:
    State* runAway(Specimen* specimen);
};

#endif // RUNAWAYSTATE_H
