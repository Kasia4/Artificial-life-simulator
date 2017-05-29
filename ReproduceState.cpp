#include "ReproduceState.h"

ReproduceState::ReproduceState()
{

}

State* ReproduceState::action(Specimen *specimen)
{
    State* result = State::action(specimen);
    std::cout<<"co ja robie tu ";
    if(result)
       return result;
    return reproduce(specimen);
}

State *ReproduceState::reproduce(Specimen *specimen)
{

}
