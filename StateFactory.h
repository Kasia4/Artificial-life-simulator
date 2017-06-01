#ifndef STATEFACTORY_H
#define STATEFACTORY_H

#include "States.h"
#include "State.h"

class StateFactory
{
public:
	static StateFactory& getInstance();
	void registerState(StateType type, State* state);
	void registerStateByNeed(NeedType type, State* state);
	State* create(StateType type);
	State* createByNeed(NeedType type);

	~StateFactory();

private:
	QMap<StateType, State*> prototypes_;
	QMap<NeedType, State*> prototypes_by_needs_;
	StateFactory();
	StateFactory( const StateFactory & ) = delete;
	StateFactory& operator=( const SpecimenSenses&) = delete;
};

#endif // STATEFACTORY_H
