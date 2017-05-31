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

State *ReproduceState::reproduce(Specimen *specimen)
{
    // create new specimen on the board from specimen and target
    //remember of the scene to add specimen
    //think about access to scene in states
    // die state needs to access scene methods too
//    Specimen* partner = dynamic_cast<Specimen*>(specimen->getTarget());
//    if(!partner->getProduceNewSpecimen())
//    {
//        specimen->setProduceNewSpecimen(true);
//        Specimen* child = new Specimen(specimen, partner);
//        SimulationScene* sim_scen = dynamic_cast<SimulationScene*>(specimen->scene());
//        sim_scen->addSpecimen(child);
//    }
//    return new State();
}
