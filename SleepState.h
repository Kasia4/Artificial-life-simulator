#ifndef SLEEPSTATE_H
#define SLEEPSTATE_H
#include "State.h"

class SleepState : public State
{
public:
    SleepState();
    void action(Specimen* specimen);
private:
    void sleep(Specimen* specimen);
};

#endif // SLEEPSTATE_H
