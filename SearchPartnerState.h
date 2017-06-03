#ifndef SEARCHPARTNERSTATE_H
#define SEARCHPARTNERSTATE_H
#include "State.h"
#include "ReproduceState.h"

class SearchPartnerState : public State
{
public:
    SearchPartnerState();
    State* action(Specimen *specimen);
	State* clone() const;
    void setFactors(Specimen* specimen);
private:
    State* searchForPartner(Specimen *specimen);
    Specimen* nearestPartner(Specimen* specimen);
};

#endif // SEARCHPARTNERSTATE_H
