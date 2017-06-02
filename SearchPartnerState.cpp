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

State* SearchPartnerState::clone() const
{
	return new SearchPartnerState(*this);
}

State* SearchPartnerState::searchForPartner(Specimen *specimen)
{
    specimen->setMove(true);
    Specimen* nearest_partner = nearestPartner(specimen);
    if(!specimen->getTarget() || specimen->getTarget() != nearest_partner)
    {
        specimen->disableTracking();
        specimen->setTarget(nearest_partner);
    }
    if(specimen->getCaughtTarget())
    {
        specimen->setMove(false);
        nearest_partner->setMove(false);
        return new ReproduceState();
    }
    return this;
}

Specimen *SearchPartnerState::nearestPartner(Specimen *specimen)
{
    return specimen->nearestSpecimen(specimen->getSpec());
}

