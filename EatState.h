#ifndef EATSTATE_H
#define EATSTATE_H
#include "State.h"

class EatState : public State
{
public:
    EatState();
    State* action(Specimen *specimen);
private:
    void eat();
};

#endif // EATSTATE_H
