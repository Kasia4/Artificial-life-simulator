#ifndef EATSTATE_H
#define EATSTATE_H
#include "State.h"
#include "GroundField.h"
class EatState : public State
{
public:
    EatState();
	State* action(Specimen *specimen);
	State* clone() const;
private:
    State* eat(Specimen* specimen);
};

#endif // EATSTATE_H
