#ifndef SEARCHFOODSTATE_H
#define SEARCHFOODSTATE_H
#include "State.h"

class SearchFoodState : public State
{
public:
    SearchFoodState();
    State* action(Specimen *specimen);
private:
    void searchForFood();
};

#endif // SEARCHFOODSTATE_H
