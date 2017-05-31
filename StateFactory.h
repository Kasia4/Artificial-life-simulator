#ifndef STATEFACTORY_H
#define STATEFACTORY_H

#include "States.h"
#include "State.h"

class StateFactory
{
public:
	static StateFactory& getInstance();
	void registerState(StateType type, State* state);
	State* create(StateType type);

	~StateFactory();

private:
	QMap<StateType, State*> prototypes_;

	StateFactory();
	StateFactory( const StateFactory & ) = delete;
	StateFactory& operator=( const SpecimenSenses&) = delete;
};

#endif // STATEFACTORY_H
