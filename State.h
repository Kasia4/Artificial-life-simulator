#ifndef STATE_H
#define STATE_H

class Specimen;
#include "Specimen.h"
#include "StateType.h"

class State
{
public:
    State();
    virtual ~State() {};
	virtual void setFactors(Specimen* specimen);

	virtual State* clone() const;
    virtual State* action(Specimen* specimen);

};
#endif // STATE_H
