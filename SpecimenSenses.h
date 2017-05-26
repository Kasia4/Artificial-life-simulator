#ifndef SPECIMENSENSES_H
#define SPECIMENSENSES_H

#include "Senses.h"
#include "ConeCollider.h"
#include "CircleCollider.h"

class SpecimenSenses : public Senses
{
public:
    SpecimenSenses();
    void setHearingRange(qreal range);
    void setSightRange(qreal range);
    void setSightAngle(qreal angle);
private:
    ConeCollider sight_;
    CircleCollider hearing_;
};

#endif // SPECIMENSENSES_H
