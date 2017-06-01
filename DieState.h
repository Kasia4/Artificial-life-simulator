#ifndef DIESTATE_H
#define DIESTATE_H
#include "State.h"
#include "SimulationScene.h"
class DieState : public State
{
public:
    DieState();
	State* clone() const;
    State* action(Specimen *specimen);
};

#endif // DIESTATE_H
