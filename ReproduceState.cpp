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

void ReproduceState::setFactors(Specimen* specimen)
{
    specimen->setAttributesStateFactors(StateAttributeFactorMap::getInstance().getAttFactorsMap(StateType::REPRODUCE));
}

State *ReproduceState::reproduce(Specimen *specimen)
{
	specimen->setMove(false);
	// create new specimen on the board from specimen and target
	//remember of the scene to add specimen
	//think about access to scene in states
	// die state needs to access scene methods too
	Specimen* partner = dynamic_cast<Specimen*>(specimen->getTarget());
	if(!partner->getProduceNewSpecimen())
	{
		specimen->setProduceNewSpecimen(true);
		Specimen* child;
		if(specimen->getSpec() == SpecimenType::CARNIVORE)
		{
			child = new CarnivoreSpecimen(specimen, partner);
		}
		else
		{
			child = new HerbivoreSpecimen(specimen, partner);
		}
		SimulationScene* sim_scen = dynamic_cast<SimulationScene*>(specimen->scene());
		sim_scen->addSpecimen(child);
		child->setPos(specimen->pos());
	}
	specimen->setNeedValue(NeedType::REPRODUCE, 0);
	partner->setNeedValue(NeedType::REPRODUCE, 0);
	partner->chooseNeed();
	specimen->chooseNeed();
	return new State();
}
