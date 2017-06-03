#ifndef SEARCHWATERSTATE_H
#define SEARCHWATERSTATE_H

#include "State.h"
#include "BoardField.h"
#include "DrinkState.h"

class SearchWaterState : public State
{
public:
    SearchWaterState();
    State* action(Specimen *specimen);
	State* clone() const;
    void setFactors(Specimen* specimen);

private:
    State* searchForWater(Specimen *specimen);
    BoardField* nearestWater(Specimen* specimen);
};

#endif // SEARCHWATERSTATE_H
