#ifndef SLEEPSTATE_H
#define SLEEPSTATE_H
#include "State.h"

class SleepState : public State
{
public:
    SleepState();
    State* action(Specimen* specimen);
private:
    State* sleep(Specimen* specimen);
};

#endif // SLEEPSTATE_H
