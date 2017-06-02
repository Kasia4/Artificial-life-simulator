#ifndef STATEATTRIBUTEFACTORMAP_H
#define STATEATTRIBUTEFACTORMAP_H

#include <QMap>
#include "AttributeType.h"
#include "StateType.h"

typedef QMap<AttributeType, qreal> AttFactorsMap;
typedef QMap<StateType, AttFactorsMap> StateFactorsMap;

class StateAttributeFactorMap
{

public:	
	static StateAttributeFactorMap& getInstance();

	void setFactor(StateType state, AttributeType attribute, qreal value);
	void setAttFactorsMap(StateType state, const AttFactorsMap& att_map);
	qreal getFactor(StateType state, AttributeType attribute) const;
	const AttFactorsMap& getAttFactorsMap(StateType state) const;

	const StateFactorsMap& map();

private:
	StateAttributeFactorMap();
	StateAttributeFactorMap( const StateAttributeFactorMap & ) = delete;
	StateAttributeFactorMap& operator=( const StateAttributeFactorMap& ) = delete;

	StateFactorsMap map_;

};

#endif // STATEATTRIBUTEFACTORMAP_H
