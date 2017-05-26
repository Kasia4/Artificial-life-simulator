#ifndef REPRODUCESTATE_H
#define REPRODUCESTATE_H
#include "State.h"

class ReproduceState : public State
{
public:
    ReproduceState();
    State* action(Specimen *specimen);
private:
    State* reproduce(Specimen* specimen);
};

#endif // REPRODUCESTATE_H
