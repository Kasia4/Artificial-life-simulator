#include "SearchPartnerState.h"


SearchPartnerState::SearchPartnerState()
{

}

State* SearchPartnerState::action(Specimen *specimen)
{

    State* result = State::action(specimen);
    if(result)
       return result;
    return searchForPartner(specimen);
}

State* SearchPartnerState::searchForPartner(Specimen *specimen)
{
    std::cout<<"szukam partnera ";
    if(!specimen->getTarget() || specimen->getTarget() != nearestPartner(specimen))
       specimen->setTarget(nearestPartner(specimen));
    if(specimen->getCaughtTarget())
       return new ReproduceState();
    return this;
}

Specimen *SearchPartnerState::nearestPartner(Specimen *specimen)
{
    return specimen->nearestSpecimen(specimen->getSpec());
}

