#ifndef DIESTATE_H
#define DIESTATE_H
#include "State.h"

class DieState : public State
{
public:
    DieState();
    void action(Specimen *specimen);
private:
    void die();
};

#endif // DIESTATE_H
