#include "ReproduceState.h"

ReproduceState::ReproduceState()
{

}

State* ReproduceState::action(Specimen *specimen)
{
    State* result = State::action(specimen);
    if(result)
       return result;
	return reproduce(specimen);
}

State* ReproduceState::clone() const
{
	return new ReproduceState(*this);
}

State *ReproduceState::reproduce(Specimen *specimen)
{
    // create new specimen on the board from specimen and target
    //remember of the scene to add specimen
    //think about access to scene in states
    // die state needs to access scene methods too
}
