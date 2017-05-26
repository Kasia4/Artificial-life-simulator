#include "SpecimenSenses.h"

SpecimenSenses::SpecimenSenses()
{
    addSense(&hearing_);
    addSense(&sight_);
}
void SpecimenSenses::setHearingRange(qreal range)
{
    hearing_.setRadius(range);
    generateShape();
}

void SpecimenSenses::setSightRange(qreal range)
{
    sight_.setRadius(range);
    generateShape();
}

void SpecimenSenses::setSightAngle(qreal angle)
{
    sight_.setApexAngle(angle);
    generateShape();
}
