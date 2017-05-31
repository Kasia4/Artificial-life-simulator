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
    Specimen* nearest_partner = nearestPartner(specimen);
    if(!specimen->getTarget() || specimen->getTarget() != nearest_partner)
    {
        specimen->disableTracking();
        specimen->setTarget(nearest_partner);
    }
    if(specimen->getCaughtTarget() && nearest_partner->getTarget() == specimen)
       return new ReproduceState();
    return this;
}

Specimen *SearchPartnerState::nearestPartner(Specimen *specimen)
{
    return specimen->nearestSpecimen(specimen->getSpec());
}

