#ifndef STATE_H
#define STATE_H

class Specimen;
#include "Specimen.h"

class State
{
public:
    State();
    virtual ~State() {};
    virtual State* action(Specimen* specimen);
};
#endif // STATE_H
