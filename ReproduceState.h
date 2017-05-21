#ifndef REPRODUCESTATE_H
#define REPRODUCESTATE_H
#include "State.h"

class ReproduceState : public State
{
public:
    ReproduceState();
    void action(Specimen *specimen);
private:
    void reproduce();
};

#endif // REPRODUCESTATE_H
