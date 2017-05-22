#ifndef SEARCHWATERSTATE_H
#define SEARCHWATERSTATE_H
#include "State.h"

class SearchWaterState : public State
{
public:
    SearchWaterState();
    State* action(Specimen *specimen);
private:
    void searchForWater();
};

#endif // SEARCHWATERSTATE_H
