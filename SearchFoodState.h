#ifndef SEARCHFOODSTATE_H
#define SEARCHFOODSTATE_H
#include "State.h"
#include "GroundField.h"
#include "EatState.h"


class SearchFoodState : public State
{
public:
    SearchFoodState();
	State* action(Specimen *specimen);
	void setFactors(Specimen *specimen);
	State* clone() const;
private:
    State* searchForFood(Specimen* specimen);
    QGraphicsItem* nearestFood(Specimen* specimen);

};

#endif // SEARCHFOODSTATE_H
