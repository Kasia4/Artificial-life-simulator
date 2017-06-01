#include "DieState.h"

DieState::DieState()
{

}

State* DieState::clone() const
{
	return new DieState(*this);
}

State* DieState::action(Specimen *specimen)
{
   // SimulationScene::removeSpecimen(specimen);
}

