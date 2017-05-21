#ifndef SEARCHPARTNERSTATE_H
#define SEARCHPARTNERSTATE_H
#include "State.h"

class SearchPartnerState : public State
{
public:
    SearchPartnerState();
    void action(Specimen *specimen);
private:
    void searchForPartner();
};

#endif // SEARCHPARTNERSTATE_H
